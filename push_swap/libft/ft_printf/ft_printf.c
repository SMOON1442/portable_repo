/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 11:05:26 by moboulah          #+#    #+#             */
/*   Updated: 2026/10/25 11:05:28 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			count += print_arg(s, &args);
			s += 2;
		}
		else
		{
			count += ft_putchar(*s);
			s++;
		}
	}
	va_end(args);
	return (count);
}
