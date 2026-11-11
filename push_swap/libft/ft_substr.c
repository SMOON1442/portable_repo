/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:38:54 by moboulah          #+#    #+#             */
/*   Updated: 2026/10/14 12:38:55 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	while (s[start++])
		i++;
	start = start - i - 1;
	if (len > i)
		len = i;
	d = malloc(len + 1);
	if (!d)
		return (NULL);
	ft_memcpy(d, s + start, len);
	d[len] = '\0';
	return (d);
}
