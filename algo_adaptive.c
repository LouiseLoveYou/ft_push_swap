/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algo_adaptive.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 13:12:10 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 13:57:56 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_strategy	choose_strategy(t_push_swap *ps, int size)
{
	if (size <= 5)
		return (SIMPLE);
	if (ps->disorder < 0.2)
		return (SIMPLE);
	if (ps->disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

void	sort_adaptive(t_push_swap *ps)
{
	ps->used = choose_strategy(ps, stack_size(ps->a));
	if (ps->used == SIMPLE)
		sort_simple(ps, stack_size(ps->a));
	else if (ps->used == MEDIUM)
		sort_medium(ps);
	else
		sort_complex(ps);
}

void	run_strategy(t_push_swap *ps, t_strategy strategy)
{
	ps->used = strategy;
	if (strategy == SIMPLE)
		sort_simple(ps, stack_size(ps->a));
	else if (strategy == MEDIUM)
		sort_medium(ps);
	else if (strategy == COMPLEX)
		sort_complex(ps);
	else
		sort_adaptive(ps);
}
