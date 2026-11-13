/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algo_simple.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 13:12:04 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 11:51:50 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_highest_val(t_stack *a)
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
