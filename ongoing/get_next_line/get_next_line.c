/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 19:02:40 by moboulah          #+#    #+#             */
/*   Updated: 2026/10/31 19:02:41 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest[1024];
	char		*str;

	str = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (rest[fd])
		str = ft_strjoin(str, rest[fd]);
	str = ft_collect(&rest[fd], fd);
	return (str);
}
