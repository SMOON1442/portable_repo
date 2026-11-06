#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	dup = malloc(i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char    *ft_strchr(const char *s, int c)
{
    if (!s)
        return (NULL);
    while (*s && *s != (unsigned char)c)
        s++;
    if (*s == (unsigned char)c)
        return ((char *)s);
    return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size && dest[i])
		i++;
	j = 0;
	while (src[j])
		j++;
	if (i == size)
		return (i + j);
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest [i + j] = '\0';
	return (i + j);
}
/*
char    *ft_strdup(const char *s)
{
    char    *dup;
    size_t    i;

    if (!s)
        return (NULL);
    i = 0;
    while (s[i])
        i++;
    dup = malloc(i + 1);
    if (!dup)
        return (NULL);
    i = 0;
    while (s[i])
        dup[i] = s[i], i++;
    dup[i] = '\0';
    return (dup);
}
*/
char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    size_t    i;
    size_t    j;

    if (!s1 || !s2)
        return (NULL);
    i = 0;
    while (s1[i])
        i++;
    j = 0;
    while (s2[j])
        j++;
    str = malloc(i + j + 1);
    if (!str)
        return (NULL);
    str[i + j] = '\0';
    while (j--)
        str[i + j] = s2[j];
    while (i--)
        str[i] = s1[i];
    return (str);
}
