/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisella <kisella@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:12:07 by kisella           #+#    #+#             */
/*   Updated: 2026/11/16 10:28:52 by kisella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks_to_b(t_push_swap *ps, int range)
{
	int	i;

	i = 0;
	while (ps->a != NULL)
	{
		if (ps->a->value <= i)
		{
			op_pb(ps);
			op_rb(ps);
			i++;
		}
		else if (ps->a->value <= i + range)
		{
			op_pb(ps);
			i++;
		}
		else
			op_ra(ps);
	}
}

void	push_back_to_a(t_push_swap *ps)
{
	int	max;
	int	pos;
	int	size;

	while (ps->b != NULL)
	{
		max = get_highest_val(ps->b);
		pos = get_val_position(ps->b, max);
		size = stack_size(ps->b);
		while (ps->b->value != max)
		{
			if (pos <= size / 2)
				op_rb(ps);
			else
				op_rrb(ps);
		}
		op_pa(ps);
	}
}

void	sort_medium(t_push_swap *ps)
{
	int	size;
	int	range;

	size = stack_size(ps->a);
	if (size <= 100)
		range = 15;
	else
		range = 35;
	push_chunks_to_b(ps, range);
	push_back_to_a(ps);
}
