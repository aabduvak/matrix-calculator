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
	char	*ret	= calloc(sizeof(*ret), 9999);
	char	chr		= 0;
	int		index	= 0;
	int		count	= 0;

	while (1)
	{
		count = read(fd, &chr, 1);
		if (count <= 0 || chr == '\n') {
			if (chr == '\n')
				ret[index++] = '\n';
			ret[index] = 0;
			break ;
		}
		ret[index++] = chr;
	}
	if (!*ret)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}