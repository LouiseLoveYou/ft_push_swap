/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algo_simple.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kisella <kisella@student.42lehavre.fr>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 13:12:04 by kisella          #+#    #+#              */
/*   Updated: 2026/11/13 13:14:49 by kisella         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	last = *a;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*a = first->next;
	last->next = first;
	first->next = NULL;
}

void	rra(t_stack **a)
{
	t_stack	*before_last;
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	before_last = NULL;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *a;
	(*a) = last;
}

int	get_highest_val(t_stack *a)
{
	int		higest;
	t_stack	*current;

	higest = a->value;
	current = a;
	while (current != NULL)
	{
		if (current->value > higest)
		{
			higest = current->value;
		}
		current = current->next;
	}
	return (higest);
}

void	sort_three(t_stack **a)
{
	int	higest;

	higest = get_highest_val(*a);
	if ((*a)->value == higest)
		ra(a);
	else if ((*a)->next->value == higest)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		op_sa(a);
}
