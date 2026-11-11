/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:41:39 by moboulah          #+#    #+#             */
/*   Updated: 2026/10/13 15:41:40 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*ptr;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	ptr = ((unsigned char *)s + i);
	while (ptr != (unsigned char *)s && *ptr != (unsigned char)c)
		ptr--;
	if (*ptr == (unsigned char)c)
		return ((char *)ptr);
	return (NULL);
}
