#include "matrix.h"

void	*multiply_matrix(void* arg)
{
	t_thread *thread = (t_thread *)arg;
	pthread_mutex_lock(thread->main->read_data);
	
	int row = thread->i / thread->main->result->height;
	int col = thread->i % thread->main->result->width;
	
	int small_width = thread->main->matrix->next->width;
	int small_height = thread->main->matrix->next->height;
	
	int max_width = thread->main->matrix->width - 1;
	int max_height = thread->main->matrix->height - 1;
	
	int k = 0;
	for (int i = row; i < row + small_width; i++)
	{
		int l = 0;
		for (int j = col; j < col + small_height; j++)
		{
			int num = 0;
			if (i <= max_height && j <= max_width)
				num = thread->main->matrix->arr[i][j];
			thread->main->result->arr[row][col] += num * thread->main->matrix->next->arr[k][l++];
		}
		k++;
	}
	usleep(5000);
	pthread_mutex_unlock(thread->main->read_data);
    pthread_exit(NULL);
}

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

void execute_threads(t_main *main)
{
	int i = -1;
	
	while (++i < main->count)
		pthread_create(main->thread[i]->thread, NULL, multiply_matrix, main->thread[i]);
	i = -1;
	while (++i < main->count)
		pthread_join(*main->thread[i]->thread, NULL);
}

void	print_result(t_main *main)
{
	printf(BOLD_GREEN);
	printf("input A: \n");
	printf(RESET);
	print_content(main->matrix);
	puts("");
	
	printf(BOLD_GREEN);
	printf("input B: \n");
	printf(RESET);
	print_content(main->matrix->next);
	puts("");
	
	printf(BOLD_BLUE);
	printf("output C: \n");
	printf(RESET);
	printf(BOLD_WHITE);
	print_content(main->result);
	printf(RESET);
	puts("");
}

int	main(int argc, char **argv)
{
	t_main	*main;
	
	if (argc != 3)
		error_args();
	main = init_main(argv);
	execute_threads(main);
	print_result(main);
	return (0);
}
