/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations_reverse.c                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 11:55:12 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 11:55:13 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_push_swap *ps)
{
	if (ps->a.size < 2)
		return ;
	rotate_down(&ps->a);
	ps->counts.rra++;
	ps->counts.total++;
	print_op("rra");
}

void	op_rrb(t_push_swap *ps)
{
	if (ps->b.size < 2)
		return ;
	rotate_down(&ps->b);
	ps->counts.rrb++;
	ps->counts.total++;
	print_op("rrb");
}

void	op_rrr(t_push_swap *ps)
{
	if (ps->a.size < 2 || ps->b.size < 2)
		return ;
	rotate_down(&ps->a);
	rotate_down(&ps->b);
	ps->counts.rrr++;
	ps->counts.total++;
	print_op("rrr");
}
