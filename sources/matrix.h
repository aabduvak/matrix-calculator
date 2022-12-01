#ifndef MATRIX_H
# define MATRIX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <fcntl.h>

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
	int				i;
	pthread_t		*thread;
	struct s_main	*main;
} t_thread;

typedef struct s_main
{
	int count;
	t_thread	**thread;
	t_matrix	*matrix;
	t_matrix	*result;
	pthread_mutex_t	*read_data;
}	t_main;

// MACRO
# define BLACK			"\033[0;30m"
# define RED			"\033[0;31m"
# define GREEN			"\033[0;32m"
# define YELLOW			"\033[0;33m"
# define CYAN			"\033[0;35m"
# define BLUE			"\033[0;36m"
# define WHITE			"\033[0;37m"
# define BOLD_RED		"\033[1;31m"
# define BOLD_GREEN		"\033[1;32m"
# define BOLD_YELLOW	"\033[0;33m"
# define BOLD_CYAN		"\033[1;35m"
# define BOLD_BLUE		"\033[1;34m"
# define BOLD_WHITE		"\033[1;37m"
# define RESET			"\033[0;0m"

# define DEBUG			printf("DEBUGING...\n");

// ERROR HANDLING
void		error_args(void);
void		error_fd(char *filename);

// GET LINE
char		*get_next_line(int fd);

// UTILS
void		*free_arr(char **ptr, int i);
char		**split(char const *s, char c);
void		print_result(t_main *main);
void		free_all(t_main *main);

// DATA FUNCTIONS
int 		get_width(char *filename);
int 		get_height(char *filename);

// MATRIX FUNCTIONS
t_matrix	*res_matrix(t_matrix *matrix);
t_matrix	*set_matrix(char **argv);
void		print_content(t_matrix *matrix);
void		*multiply_matrix(void* arg);

// THREAD FUNCTIONS
void		init_threads(t_main *main);
void		execute_threads(t_main *main);

#endif