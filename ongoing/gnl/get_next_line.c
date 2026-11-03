/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:45:39 by moboulah          #+#    #+#             */
/*   Updated: 2026/10/19 21:45:43 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*final_word(char *buf)
{
	char	*line;
	size_t	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i--)
		line[i] = buf[i];
	return (line);
}

static int	split_line(char *src, char *nl, char **rest, t_list **lst)
{
	char	*tmp;

	tmp = final_word(src);
	if (!tmp || !ft_lstadd_back(lst, tmp))
		return (free(tmp), 0);
	tmp = ft_strdup(nl + 1);
	if (!tmp)
		return (0);
	free(*rest);
	*rest = tmp;
	return (1);
}

static int	get_rest(char **rest, t_list **lst)
{
	char	*newline;

	if (!*rest)
		return (1);
	newline = ft_strchr(*rest, '\n');
	if (newline)
	{
		if (!split_line(*rest, newline, rest, lst))
			return (0);
		return (2);
	}
	if (!ft_lstadd_back(lst, *rest))
		return (0);
	*rest = NULL;
	return (1);
}

static int	read_to_list(int fd, char **rest, t_list **lst)
{
	char	buf[BUFFER_SIZE + 1];
	char	*newline;
	char	*tmp;
	ssize_t	n;

	n = 1;
	while (n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (0);
		buf[n] = '\0';
		newline = ft_strchr(buf, '\n');
		if (newline)
			return (split_line(buf, newline, rest, lst));
		if (n > 0)
		{
			tmp = ft_strdup(buf);
			if (!tmp || !ft_lstadd_back(lst, tmp))
				return (free(tmp), 0);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*rest[1024];
	t_list		*lst;
	char		*str;
	int			status;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	lst = NULL;
	status = get_rest(&rest[fd], &lst);
	if (!status)
		return (ft_lstclear(lst), NULL);
	if (status != 2 && !read_to_list(fd, &rest[fd], &lst))
		return (ft_lstclear(lst), NULL);
	if (!lst)
		return (NULL);
	str = ft_lstjoin(lst);
	ft_lstclear(lst);
	if (str && !*str)
		return (free(str), NULL);
	printf("%s", str);
	return (str);
}
