#include "matrix.h"

t_main	*init_main(char **argv)
{
	t_main *main = calloc(1, sizeof(t_main));
	main->matrix = set_matrix(argv);
	main->result = res_matrix(main->matrix);
	
	init_threads(main);
	main->read_data = calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(main->read_data, NULL);
	return (main);
}


int	main(int argc, char **argv)
{
	t_main	*main;
	
	if (argc != 3)
		error_args();
	main = init_main(argv);
	execute_threads(main);
	print_result(main);
	free_all(main);
	return (0);
}
