#include "get_next_line.h"
#include <stdio.h>

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

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*buf1;
	static char	*rest;
	char	*str;
	char	*str1;
	char	*rest1;
	int	n;

	if (fd < 0 || read(fd, NULL, 0) < 0)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	str = ft_strdup("");
	n = 1;
	if (rest)
	{
		if (ft_strchr(rest, '\n'))
		{
			rest1 = final_word(rest);
			str1 = ft_strjoin(str, rest1);
			free(rest1);
			rest1 = ft_strdup(ft_strchr(rest, '\n') + 1);
			free(rest);
			rest = rest1;
			free(str);
			str = str1;
			return (str);
		//	ft_strlcat(str, rest1, ft_strlen(rest1) + 1);
		}
		else
		{
			str1 = ft_strjoin(str, rest);
			free(rest);
			rest = NULL;
			free(str);
			str = str1;
		}
		//	ft_strlcat(str, rest, ft_strlen(rest) + 1);
	}
	while (n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
		{
			free(rest);
			rest = NULL;
			free(str);
			return (NULL);
		}
		buf[n] = '\0';
		if (!ft_strchr(buf, '\n'))
		{
			str1 = ft_strjoin(str, buf);
			free(str);
			str = str1;
		}
		//	ft_strlcat(str, buf, ft_strlen(str) + ft_strlen(buf) + 1);
		else
		{
			rest = ft_strdup(ft_strchr(buf, '\n') + 1);
			buf1 = final_word(buf);
		//	ft_strlcat(str, buf1, ft_strlen(str) + ft_strlen(buf1+ 1));
			str1 = ft_strjoin(str, buf1);
			free(str);
			str = str1;
			free(buf1);
			return (str);
		}
	}
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
/*
#include <fcntl.h>
int	main(){

	int	fd;

	fd = open("test.txt", 0);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
*/
