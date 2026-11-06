#include "get_next_line.h"

char	*final_word(char *buf)
{
	int		i;
	char	*final;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	final = malloc(i + 2);
	if (!final)
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		final[i] = buf[i];
		i++;
	}
	final[i] = '\n';
	final[i + 1] = '\0';
	return (final);
}

static char	*append_str(char *str, char *buf)
{
	char	*str1;

	str1 = ft_strjoin(str, buf);
	free(str);
	return (str1);
}

static char	*handle_rest(char **rest, char **str)
{
	char	*rest1;

	if (!*rest)
		return (NULL);
	if (ft_strchr(*rest, '\n'))
	{
		rest1 = final_word(*rest);
		*str = append_str(*str, rest1);
		free(rest1);
		rest1 = ft_strdup(ft_strchr(*rest, '\n') + 1);
		free(*rest);
		*rest = rest1;
		return (*str);
	}
	*str = append_str(*str, *rest);
	free(*rest);
	*rest = NULL;
	return (NULL);
}

static char	*fill_str(int fd, char *str, char **rest)
{
	char	buf[BUFFER_SIZE + 1];
	char	*buf1;
	int		n;

	n = 1;
	while (n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (free(*rest), *rest = NULL, free(str), NULL);
		buf[n] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			*rest = ft_strdup(ft_strchr(buf, '\n') + 1);
			buf1 = final_word(buf);
			str = append_str(str, buf1);
			free(buf1);
			return (str);
		}
		str = append_str(str, buf);
	}
	if (!*str)
		return (free(str), NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*str;
	char		*str1;

	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (free(rest), rest = NULL, NULL);
	str = ft_strdup("");
	str1 = handle_rest(&rest, &str);
	if (str1)
		return (str1);
	return (fill_str(fd, str, &rest));
}
