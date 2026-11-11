/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:53:11 by moboulah          #+#    #+#             */
/*   Updated: 2026/10/27 20:53:13 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (ft_putstr("(null)"));
	count = 0;
	while (s[count])
	{
		ft_putchar(s[count]);
		count++;
	}
	return (count);
}
