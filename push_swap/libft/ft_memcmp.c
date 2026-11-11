/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 09:03:00 by moboulah          #+#    #+#             */
/*   Updated: 2026/10/14 09:03:02 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*m1;
	const unsigned char	*m2;

	m1 = (const unsigned char *)s1;
	m2 = (const unsigned char *)s2;
	while (n && *m1 == *m2)
	{
		m1++;
		m2++;
		n--;
	}
	if (!n)
		return (0);
	return (*m1 - *m2);
}
