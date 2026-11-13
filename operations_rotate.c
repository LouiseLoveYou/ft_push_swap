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

static void	rotate_up(t_stack *s)
{
	int	tmp;
	int	i;

	tmp = s->data[0];
	i = 1;
	while (i < s->size)
	{
		s->data[i - 1] = s->data[i];
		i++;
	}
	s->data[s->size - 1] = tmp;
}

void	rotate_down(t_stack *s)
{
	int	tmp;
	int	i;

	tmp = s->data[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->data[i] = s->data[i - 1];
		i--;
	}
	s->data[0] = tmp;
}

void	op_ra(t_push_swap *ps)
{
	if (ps->a.size < 2)
		return ;
	rotate_up(&ps->a);
	ps->counts.ra++;
	ps->counts.total++;
	print_op("ra");
}

void	op_rb(t_push_swap *ps)
{
	if (ps->b.size < 2)
		return ;
	rotate_up(&ps->b);
	ps->counts.rb++;
	ps->counts.total++;
	print_op("rb");
}

void	op_rr(t_push_swap *ps)
{
	if (ps->a.size < 2 || ps->b.size < 2)
		return ;
	rotate_up(&ps->a);
	rotate_up(&ps->b);
	ps->counts.rr++;
	ps->counts.total++;
	print_op("rr");
}
