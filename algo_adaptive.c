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

t_strategy	choose_strategy(const t_push_swap *ps)
{
	if (ps->disorder < 0.2)
		return (SIMPLE);
	if (ps->disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

void	sort_adaptive(t_push_swap *ps)
{
	ps->used = choose_strategy(ps);
	if (stack_size(ps->a) <= 5)
		sort_simple(ps, stack_size(ps->a));
	else if (ps->used == SIMPLE)
		sort_simple(ps, stack_size(ps->a));
	else if (ps->used == MEDIUM)
		sort_medium(ps);
	else
		sort_complex(ps);
}

void	run_strategy(t_push_swap *ps, t_strategy strategy)
{
	ps->used = strategy;
	if (strategy == ADAPTIVE)
		sort_adaptive(ps);
	else if (strategy == MEDIUM && stack_size(ps->a) > 5)
		sort_medium(ps);
	else if (strategy == COMPLEX && stack_size(ps->a) > 5)
		sort_complex(ps);
	else
		sort_simple(ps, stack_size(ps->a));
}
