#include "matrix.h"

char	*get_next_line(int fd)
{
	char	*ret	= calloc(sizeof(*ret), 9999);
	char	chr		= 0;
	int		index	= 0;
	int		count	= 0;

	while (1)
	{
		count = read(fd, &chr, 1);
		if (count <= 0 || chr == '\n') {
			if (chr == '\n')
				ret[index++] = '\n';
			ret[index] = 0;
			break ;
		}
		ret[index++] = chr;
	}
	if (!*ret)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

void	error_args(void)
{
	printf("invalid number of arguments\n");
	exit(1);	
}

void	error_fd(char *filename)
{
	printf("error occured while opening file: %s\n", filename);
	exit(1);
}

void	print_result(t_main *main)
{
	printf(BOLD_GREEN);
	printf("input A: \n");
	printf(RESET);
	printf(YELLOW);
	print_content(main->matrix);
	printf(RESET);
	puts("");
	
	printf(BOLD_GREEN);
	printf("input B: \n");
	printf(RESET);
	printf(YELLOW);
	print_content(main->matrix->next);
	printf(RESET);
	puts("");
	
	printf(BOLD_BLUE);
	printf("output C: \n");
	printf(RESET);
	printf(BOLD_WHITE);
	print_content(main->result);
	printf(RESET);
	puts("");
}
