#include "matrix.h"

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