/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 18:42:10 by moboulah          #+#    #+#             */
/*   Updated: 2026/10/27 18:42:12 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	print_arg(const char *s, va_list *args);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putaddr(void *p);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_puthex(unsigned long n);
int	ft_putupperhex(unsigned int n);

#endif
