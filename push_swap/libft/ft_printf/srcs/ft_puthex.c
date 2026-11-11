/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:50:52 by moboulah          #+#    #+#             */
/*   Updated: 2026/10/27 20:50:53 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16);
	count += ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}
