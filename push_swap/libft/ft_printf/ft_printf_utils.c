/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 10:02:20 by moboulah          #+#    #+#             */
/*   Updated: 2026/10/28 10:02:22 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(const char *s, va_list *args)
{
	int	count;

	count = 0;
	if (*(s + 1) == 'c')
		count += ft_putchar(va_arg(*args, int));
	if (*(s + 1) == 's')
		count += ft_putstr(va_arg(*args, char *));
	if (*(s + 1) == 'p')
		count += ft_putaddr(va_arg(*args, void *));
	if (*(s + 1) == 'd' || *(s + 1) == 'i')
		count += ft_putnbr(va_arg(*args, int));
	if (*(s + 1) == 'u')
		count += ft_putunbr(va_arg(*args, unsigned int));
	if (*(s + 1) == 'x')
		count += ft_puthex((unsigned long)va_arg(*args, unsigned int));
	if (*(s + 1) == 'X')
		count += ft_putupperhex(va_arg(*args, unsigned int));
	if (*(s + 1) == '%')
		count += ft_putchar('%');
	return (count);
}
