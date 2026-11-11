/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:17:15 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/11 13:57:28 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || !b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
//	ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	pa(b, a);
	ft_printf("pb\n");
}
