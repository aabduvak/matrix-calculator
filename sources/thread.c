#include "matrix.h"

void init_threads(t_main *main)
{
	int i = -1;
	int count = (main->matrix->width) * (main->matrix->height); // number of threads

	t_thread **threads = calloc(count, sizeof(t_thread *));
	while (++i < count)
	{
		threads[i] = calloc(1, sizeof(t_thread));
		threads[i]->i = i;
		threads[i]->main = main;
		threads[i]->thread = calloc(1, sizeof(pthread_t));
	}
	main->thread = threads;
	main->count = count;
}

void execute_threads(t_main *main)
{
	int i = -1;
	
	while (++i < main->count)
		pthread_create(main->thread[i]->thread, NULL, multiply_matrix, main->thread[i]); // create thread and execute it
	i = -1;
	while (++i < main->count)
		pthread_join(*main->thread[i]->thread, NULL); // wait until thread finish execution
}
