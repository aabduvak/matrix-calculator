#ifndef GNL_H
# define GNL_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *str, unsigned int start, size_t leng);
char	*ft_strchr(const char *str, int c);
char	*get_next_line(int fd);

#endif