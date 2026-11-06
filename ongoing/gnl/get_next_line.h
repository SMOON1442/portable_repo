#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*final_word(char *str);
size_t	ft_strlen(char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif
