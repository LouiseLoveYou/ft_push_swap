/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations_push.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 11:54:15 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 11:54:22 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_top(t_stack *from, t_stack *to)
{
	int	value;

	stack_pop(from, &value);
	stack_push(to, value);
}

void	op_pa(t_push_swap *ps)
{
	if (ps->b.size == 0)
		return ;
	push_top(&ps->b, &ps->a);
	ps->counts.pa++;
	ps->counts.total++;
	print_op("pa");
}

void	op_pb(t_push_swap *ps)
{
	if (ps->a.size == 0)
		return ;
	push_top(&ps->a, &ps->b);
	ps->counts.pb++;
	ps->counts.total++;
	print_op("pb");
}
