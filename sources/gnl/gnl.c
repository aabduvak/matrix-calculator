#include <gnl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static void	*ft_clear_backup(char **backup)
{
	free(*backup);
	*backup = NULL;
	return (*backup);
}

static char	*ft_init_string(char **backup)
{
	char	*last_char;
	char	*result;
	size_t	backup_leng;

	if (!*backup)
		return (*backup);
	backup_leng = strlen(*backup);
	if (!backup_leng)
		return (ft_clear_backup(backup));
	last_char = strchr(*backup, '\n');
	if (!last_char)
	{
		result = ft_substr(*backup, 0, backup_leng);
		**backup = 0;
		return (result);
	}
	result = ft_substr(*backup, 0, last_char - *backup + 1);
	strncpy(*backup, last_char + 1, backup_leng);
	return (result);
}

static char	*ft_update(char **backup, char *str)
{
	char	*old_slice;

	old_slice = *backup;
	*backup = ft_strjoin(*backup, str);
	if (old_slice)
		free(old_slice);
	return (*backup);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*backup[1024];
	char		slice[BUFFER_SIZE + 1];
	int			read_bytes;

	read_bytes = 1;
	result = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (result);
	while (read_bytes && !ft_strchr(backup[fd], '\n'))
	{
		read_bytes = read(fd, slice, BUFFER_SIZE);
		slice[read_bytes] = '\0';
		if (read_bytes < 0 || !ft_update(&backup[fd], slice))
			return (ft_clear_backup(&backup[fd]));
	}
	result = ft_init_string(&backup[fd]);
	return (result);
}