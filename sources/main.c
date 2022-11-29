#include <general.h>
#include <gnl.h>
#include <errors.h>
#include <macro.h>
#include <utils.h>

//void* multi(void* arg)
//{
//    int i = step_i++; //i denotes row number of resultant matC
   
//    for (int j = 0; j < MAX; j++)
//      for (int k = 0; k < MAX; k++)
//        matC[i][j] += matA[i][k] * matB[k][j];
//}

typedef struct s_matrix
{
	int **arr;
	int	i;
	int width;
	int height;
	struct s_matrix *next;
	struct s_matrix *prev;
} t_matrix;


typedef struct s_thread
{
	int			result;
	int			i;
	pthread_t	*thread;
	t_matrix	*matrix;
} t_thread;

int get_width(char *filename)
{
	int fd;
	int i;
	char *line;
	int count;
	
	count = 0;
	i = -1;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line[++i])
		if (line[i] >= '0' && line[i] <= '9')
			count++;
	free(line);
	close(fd);
	return (count);
}

int get_height(char *filename)
{
	int fd;
	char *line;
	int count;
	
	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		perror("matrix");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	fill_matrix(char *line, int *arr)
{
	int i;
	char **str;
	
	i = -1;
	str = split(line, ' ');
	while (str[++i])
		arr[i] = atoi(str[i]);
	free_arr(str, i);
}

t_matrix *init_matrix(char **argv, int id)
{
	int			i;
	t_matrix	*matrix;
	
	i = -1;
	matrix = (t_matrix *)malloc(sizeof(t_matrix) * 1);
	matrix->height = get_height(argv[id]);
	matrix->width = get_width(argv[id]);
	matrix->arr = (int **)malloc(sizeof(int *) * (matrix->height));
	while (++i < matrix->height)
		matrix->arr[i] = (int *)malloc(sizeof(int) * (matrix->width));
	matrix->next = NULL;
	matrix->prev = NULL;
	matrix->i = id - 1;
	if (matrix->i == 1)
		matrix->height -= 2;
	return (matrix);
}

void	fill_data(t_matrix *matrix, char *filename)
{
	int		fd;
	int		i;
	char	*line;

	i = -1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_fd(filename);
	while (++i < matrix->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("line: %s", line);
		fill_matrix(line, matrix->arr[i]);
		free(line);
	}
	close(fd);
}

void	print_content(t_matrix *matrix)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < matrix->height)
	{
		while (++j < matrix->width)
			printf("%d ", matrix->arr[i][j]);
		printf("\n");
		j = -1;
	}
}

int	main(int argc, char **argv)
{
	t_matrix	*matrix;

	if (argc != 3)
		error_args();
	matrix = init_matrix(argv, 1);
	matrix->next = init_matrix(argv, 2);
	matrix->next->prev = matrix;
	
	fill_data(matrix, argv[1]);
	fill_data(matrix->next, argv[2]);
	puts("");
	print_content(matrix);
	puts("");
	print_content(matrix->next);
	return (0);
}
