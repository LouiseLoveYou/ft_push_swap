/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kisella <kisella@student.42lehavre.fr>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 13:11:44 by kisella          #+#    #+#              */
/*   Updated: 2026/11/13 10:48:43 by kisella         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(char *name)
{
	ft_putstr_fd(name, 1);
	ft_putchar_fd('\n', 1);
}

static void	swap_top(t_stack *s)
{
	int	tmp;

	tmp = s->data[0];
	s->data[0] = s->data[1];
	s->data[0] = tmp;
}

void	op_sa(t_push_swap *ps)
{
	if (ps->a.size < 2)
		return ;
	swap_top(&ps->a);
	ps->counts.sa++;
	ps->counts.total++;
	print_op("sa");
}

void	op_sb(t_push_swap *ps)
{
	if (ps->b.size < 2)
		return ;
	swap_top(&ps->b);
	ps->counts.sb++;
	ps->counts.total++;
	print_op("sb");
}

void	op_ss(t_push_swap *ps)
{
	if (ps->a.size < 2 || ps->b.size < 2)
		return ;
	swap_top(&ps->a);
	swap_top(&ps->b);
	ps->counts.ss++;
	ps->counts.total++;
	print_op("ss");
}
