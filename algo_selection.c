/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algo_selection.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/16 11:45:00 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/16 11:45:00 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top(t_push_swap *ps, int value)
{
	int	size;
	int	pos;

	size = stack_size(ps->a);
	pos = get_val_position(ps->a, value);
	while (ps->a->value != value)
	{
		if (pos <= size / 2)
			op_ra(ps);
		else
			op_rra(ps);
	}
}

void	sort_selection(t_push_swap *ps)
{
	int	target;
	int	size;

	size = stack_size(ps->a);
	target = 0;
	while (target < size)
	{
		rotate_to_top(ps, target);
		op_pb(ps);
		target++;
	}
	while (ps->b)
		op_pa(ps);
}
