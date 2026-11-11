/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 09:14:08 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/11 14:14:17 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

void	sort_simple(t_stack **a)
{
	t_stack	*tmp;
	int	size;

	tmp = *a;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	while (size)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a);
		else
			ra(a);
		size--;
	}
}
