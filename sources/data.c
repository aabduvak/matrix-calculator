#include "matrix.h"

int get_width(char *filename)
{
	int fd;
	int i;
	char *line;
	int count;
	
	count = 0;
	i = -1;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line[++i])
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			while (line[i] && line[i] != ' ')
				i++;
			count++;
		}
	}
	free(line);
	close(fd);
	return (count);
}

int get_height(char *filename)
{
	int fd;
	char *line;
	int count;
	
	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_fd(filename);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || !strncmp(line, "\n", 1))
			break;
		count++;
		free(line);
	}
	return (count);
}