#include "matrix.h"

void	free_all(t_main *main) // free all allocated memory blocks
{
	int	i = -1;

	free(main->read_data);
	while (++i < main->matrix->next->height)
		free(main->matrix->next->arr[i]);
	free(main->matrix->next->arr);
	free(main->matrix->next);
	
	i = -1;
	while (++i < main->matrix->height)
		free(main->matrix->arr[i]);
	free(main->matrix->arr);
	free(main->matrix);
	
	i = -1;
	while (++i < main->result->height)
		free(main->result->arr[i]);
	free(main->result->arr);
	free(main->result);
	
	i = -1;
	while (++i < main->count)
	{
		free(main->thread[i]->thread);
		main->thread[i]->main = NULL;
		free(main->thread[i]);
	}
	free(main->thread);
	free(main);
}
