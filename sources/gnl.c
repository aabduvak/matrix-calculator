#include "matrix.h"

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