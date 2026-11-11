/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 20:03:35 by moboulah          #+#    #+#             */
/*   Updated: 2026/10/14 20:04:00 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*cpy;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && in_set(s1[i], set))
		i++;
	start = i;
	i = ft_strlen(s1);
	while (i > start && in_set(s1[i - 1], set))
		i--;
	end = i;
	cpy = malloc(end - start + 1);
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s1 + start, end - start + 1);
	return (cpy);
}
