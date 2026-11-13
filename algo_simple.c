/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisella <kisella@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:12:04 by kisella           #+#    #+#             */
/*   Updated: 2026/11/13 14:18:40 by kisella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_val_position(t_stack *a, int target_val)
{
	int		pos;
	t_stack	*current;

	pos = 0;
	current = a;
	while (current != NULL)
	{
		if (current->value == target_val)
			return (pos);
		pos++;
		current = current->next;
	}
	return (pos);
}

int	get_lowest_val(t_stack *a)
{
	int		lowest;
	t_stack	*current;

	lowest = a->value;
	current = a;
	while (current != NULL)
	{
		if (current->value < lowest)
			lowest = current->value;
		current = current->next;
	}
	return (lowest);
}

int	get_highest_val(t_stack *a)
{
	int		highest;
	t_stack	*current;

	highest = a->value;
	current = a;
	while (current != NULL)
	{
		if (current->value > highest)
			highest = current->value;
		current = current->next;
	}
	return (highest);
}

void	sort_three(t_push_swap *ps)
{
	int	highest;

	if (stack_is_sorted(ps->a))
		return ;
	highest = get_highest_val(ps->a);
	if (ps->a->value == highest)
		op_ra(ps);
	else if (ps->a->next->value == highest)
		op_rra(ps);
	if (ps->a->value > ps->a->next->value)
		op_sa(ps);
}

void	sort_four(t_push_swap *ps)
{
	t_stack	*lowest;

	t_stack * a
	lowest = get_lowest_val(ps->a)
}
