#include "matrix.h"

void init_threads(t_main *main)
{
	int i = -1;
	int count = (main->matrix->width) * (main->matrix->height);

	t_thread **threads = calloc(count, sizeof(t_thread *));
	while (++i < count)
	{
		threads[i] = calloc(1, sizeof(t_thread));
		threads[i]->i = i;
		threads[i]->main = main;
		threads[i]->result = 0;
		threads[i]->thread = calloc(1, sizeof(pthread_t));
	}
	main->thread = threads;
	main->count = count;
}
