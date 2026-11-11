/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:57:58 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/11 12:25:48 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ra(t_stack **a)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!a || !*a || !((*a)->next))
		return ;
	if (!((*a)->next->next))
	{
		(*a)->next->next = *a;
		*a = (*a)->next;
		(*a)->next->next = NULL;
		return ;
	}
	tmp = (*a)->next;
	current = *a;
	while (current->next)
		current = current->next;
	current->next = *a;
	(*a)->next = NULL;
	*a = tmp;
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	ra(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

void	rra(t_stack **a)
{
	t_stack	*current;
	t_stack	*previous;

	if (!a || !*a || !((*a)->next))
		return ;
	if (!((*a)->next->next))
	{
		(*a)->next->next = *a;
		*a = (*a)->next;
		(*a)->next->next = NULL;
		return ;
	}
	previous = *a;
	current = previous->next;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	current->next = *a;
	*a = current;
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	rra(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}

t_stack	*ft_stacknew(int a)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->content = a;
	stack->next = NULL;

	return (stack);
}

void	ft_stack_addfront(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
}
/*
#include <stdio.h>
int main()
{
	t_stack	*a = NULL;
	t_stack	*tmp;
	int	i = 1;

	while (i <= 5)
		ft_stack_addfront(&a, ft_stacknew(i++));
	tmp = a;
	while (tmp)
	{
		printf("[%d] ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	rra(&a);
	tmp = a;
	while (tmp)
	{
		printf("[%d] ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}
*/
