/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupperhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:51:01 by moboulah          #+#    #+#             */
/*   Updated: 2026/10/27 20:51:02 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putupperhex(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putupperhex(n / 16);
	count += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (count);
}
