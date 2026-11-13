/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisella <kisella@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:12:04 by kisella           #+#    #+#             */
/*   Updated: 2026/11/13 15:52:32 by kisella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	lowest;

	lowest = get_lowest_val(ps->a);
	while (ps->a->value != lowest)
	{
		if (get_val_position(ps->a, lowest) > 1)
			op_rra(ps);
		else
			op_ra(ps);
	}
	op_pb(ps);
	sort_three(ps);
	op_pa(ps);
}

void	sort_five(t_push_swap *ps)
{
	int	lowest;

	lowest = get_lowest_val(ps->a);
	while (ps->a->value != lowest)
	{
		if (get_val_position(ps->a, lowest) > 2)
			op_rra(ps);
		else
			op_ra(ps);
	}
	op_pb(ps);
	sort_four(ps);
	op_pa(ps);
}

void	sort_simple(t_push_swap *ps, int size)
{
	if (size < 2)
		return ;
	if (size == 2)
		op_sa(ps);
	else if (size == 3)
		sort_three(ps);
	else if (size == 4)
		sort_four(ps);
	else if (size == 5)
		sort_five(ps);
}
