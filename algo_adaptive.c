/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algo_adaptive.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 13:12:10 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 13:46:37 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_push_swap *ps)
{
	if (ps->a.size <= 5)
		sort_simple(ps);
	else if (ps->disorder < 0.2)
		sort_simple(ps);
	else if (ps->disorder < 0.5)
		sort_medium(ps);
	else
		sort_complex(ps);
}

void	run_strategy(t_push_swap *ps, t_strategy strategy)
{
	if (strategy == SIMPLE)
		sort_simple(ps);
	else if (strategy == MEDIUM)
		sort_medium(ps);
	else if (strategy == COMPLEX)
		sort_complex(ps);
	else
		sort_adaptive(ps);
}
