/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 17:58:41 by moboulah          #+#    #+#             */
/*   Updated: 2026/10/13 17:58:43 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*needle;
	size_t		i;

	if (!*little)
		return ((char *)big);
	while (len && *big)
	{
		i = 0;
		needle = little;
		while (i < len && *needle && big[i] == *needle)
		{
			needle++;
			i++;
		}
		if (!*needle)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
