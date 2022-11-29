#include <general.h>
#include <utils.h>

int	count_words(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static char	*create_str(char const *str, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	ptr = (char *) malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	strncpy(ptr, str, i + 1);
	ptr[i] = 0;
	return (ptr);
}

void	*free_arr(char **ptr, int i)
{
	while (i > 0)
		free(ptr[i--]);
	free(ptr);
	return (NULL);
}

char	**split(char const *s, char c)
{
	int		i;
	int		leng;
	char	**ptr;

	if (!s)
		return (NULL);
	leng = count_words(s, c);
	ptr = (char **)malloc(sizeof(char *) * (leng + 1));
	if (!(ptr))
		return (NULL);
	i = -1;
	while (++i < leng)
	{
		while (s[0] == c)
			s++;
		ptr[i] = create_str(s, c);
		if (!ptr[i])
			return (free_arr(ptr, i));
		s = s + strlen(ptr[i]);
	}
	ptr[i] = 0;
	return (ptr);
}
