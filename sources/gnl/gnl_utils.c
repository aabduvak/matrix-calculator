#include <gnl.h>

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (0);
	while (*str != (char) c && *str != '\0')
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s1 || !s2)
	{
		if (s1)
			return (strncpy((char *)malloc(strlen(s1)),
					s1, strlen(s1)));
		if (s2)
			return (strncpy((char *)malloc(strlen(s2)),
					s2, strlen(s2)));
		return (0);
	}
	str = (char *) malloc((strlen(s1) + strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	size_t	s_len;
	size_t	sub_len;
	char	*substr;

	if (!s)
		return (0);
	s_len = strlen(s);
	if (s_len <= start)
	{
		substr = (char *)malloc(sizeof(char));
		*substr = 0;
		return (substr);
	}
	sub_len = s_len - start;
	if (sub_len > len)
		sub_len = len;
	substr = (char *)malloc(sizeof(char) * (sub_len + 1));
	if (!substr)
		return (substr);
	index = 0;
	while (index < sub_len)
		substr[index++] = s[start++];
	substr[index] = '\0';
	return (substr);
}