#include "matrix.h"

t_main	*init_main(char **argv)
{
	// allocate memory address and fill address blocks with 0
	t_main *main = calloc(1, sizeof(t_main));
	
	// get data from files and set them to main struct
	main->matrix = set_matrix(argv);
	main->result = res_matrix(main->matrix);
	
	// initialize threads
	init_threads(main);
	
	// allocate memory for pthread_mutex_t variable
	main->read_data = calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(main->read_data, NULL);
	return (main);
}


int	main(int argc, char **argv)
{
	t_main	*main;
	
	// if argument number is not 3 print error message:
	// argv[0] -> executable name
	// argv[1] -> filename
	// argv[2] -> filename
	if (argc != 3)
		error_args();
	
	// create new main struct which contains all data
	main = init_main(argv);
	
	// start execute threads and wait their job to be done
	execute_threads(main);
	
	// after execution threads print final matrix
	print_result(main);
	
	// free all data which was allocated on the heap
	free_all(main);
	return (0);
}
