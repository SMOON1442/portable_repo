/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 05:57:57 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/01 05:57:59 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*ptr;

	if (!s)
		return (NULL);
	ptr = (unsigned char *)s;
	while (*ptr && *ptr != (unsigned char)c)
		ptr++;
	if (*ptr == (unsigned char)c)
		return ((char *)ptr);
	return (NULL);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = 0;
	while (s1[len1])
		len1++;
	len2 = 0;
	while (s2[len2])
		len2++;
	sj = malloc(len1 + len2 + 1);
	if (!sj)
		return (NULL);
	sj[len1 + len2] = '\0';
	while (len2--)
		sj[len1 + len2] = s2[len2];
	while (len1--)
		sj[len1] = s1[len1];
	return (sj);
}

char	*final_word(char *buf)
{
	int		i;
	char	*final;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	final = malloc(i + 2);
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

char	*ft_collect(char **rest, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*str;
	int		n;
	char	*final;

	n = 1;
	while (n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n <= 0)
			return (NULL);
		buf[n] = '\0';
		if (!ft_strchr(buf, '\n'))
			str = ft_strjoin(str, buf);
		else
		{
			final = final_word(buf);
			str = ft_strjoin(str, final);
			free(*rest);
			*rest = ft_strdup(ft_strchr(buf, '\n') + 1);
			break ;
		}
	}
	return (str);
}
