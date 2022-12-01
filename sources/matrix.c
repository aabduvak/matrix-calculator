#include "matrix.h"

static void	fill_matrix(char *line, int *arr)
{
	int i;
	char **str;
	
	i = -1;
	str = split(line, ' ');
	while (str[++i])
		arr[i] = atoi(str[i]);
	free_arr(str, i);
}

static t_matrix *init_matrix(char **argv, int id)
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
	return (matrix);
}

t_matrix	*res_matrix(t_matrix *matrix)
{
	int			i;
	t_matrix	*result;
	
	i = -1;
	result = (t_matrix *)calloc(1, sizeof(t_matrix));
	result->height = matrix->height;
	result->width = matrix->width;
	result->arr = (int **)calloc((result->height), sizeof(int *));
	while (++i < result->height)
		result->arr[i] = (int *)calloc((result->width), sizeof(int));
	result->next = NULL;
	result->prev = NULL;
	result->i = 2;
	return (result);
}

static void	fill_data(t_matrix *matrix, char *filename)
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
		fill_matrix(line, matrix->arr[i]);
		free(line);
	}
	close(fd);
}

void	print_content(t_matrix *matrix)
{
	int	i;
	int	j;
	t_matrix *mx;

	i = -1;
	j = -1;
	mx = matrix;
	while (mx)
	{	
		while (++i < mx->height)
		{
			while (++j < mx->width)
				printf("%d ", mx->arr[i][j]);
			printf("\n");
			j = -1;
		}
		mx = mx->next;
		i = -1;
		puts("");
	}
}

t_matrix *set_matrix(char **argv)
{
	t_matrix	*matrix;

	matrix = init_matrix(argv, 1);
	matrix->next = init_matrix(argv, 2);
	matrix->next->prev = matrix;
	
	fill_data(matrix, argv[1]);
	fill_data(matrix->next, argv[2]);
	
	return (matrix);
}