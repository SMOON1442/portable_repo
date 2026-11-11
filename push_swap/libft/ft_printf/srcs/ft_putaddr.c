/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:50:27 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/11 09:04:33 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(void *p)
{
	unsigned long	n;
	int				count;

	if (!p)
		return (ft_putstr("(nil)"));
	n = (unsigned long)p;
	count = ft_putstr("0x");
	count += ft_puthex(n);
	return (count);
}
