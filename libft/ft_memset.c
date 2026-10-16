/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 18:35:56 by moboulah          #+#    #+#             */
/*   Updated: 2026/10/13 18:35:58 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	a = (unsigned char)c;
	while (n--)
	{
		*ptr = a;
		ptr++;
	}
	return (s);
}
