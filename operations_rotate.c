/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations_rotate.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 11:54:48 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 11:54:49 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_up(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	first = *s;
	*s = first->next;
	last = stack_last(*s);
	last->next = first;
	first->next = NULL;
}

void	rotate_down(t_stack **s)
{
	t_stack	*previous;
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	previous = NULL;
	last = *s;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = *s;
	*s = last;
}

void	op_ra(t_push_swap *ps)
{
	if (!ps->a || !ps->a->next)
		return ;
	rotate_up(&ps->a);
	ps->counts.ra++;
	ps->counts.total++;
	print_op("ra");
}

void	op_rb(t_push_swap *ps)
{
	if (!ps->b || !ps->b->next)
		return ;
	rotate_up(&ps->b);
	ps->counts.rb++;
	ps->counts.total++;
	print_op("rb");
}

void	op_rr(t_push_swap *ps)
{
	if (!ps->a || !ps->a->next || !ps->b || !ps->b->next)
		return ;
	rotate_up(&ps->a);
	rotate_up(&ps->b);
	ps->counts.rr++;
	ps->counts.total++;
	print_op("rr");
}
