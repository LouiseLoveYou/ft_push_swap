/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algo_complex.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 13:12:09 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 10:51:54 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_bits(int n)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < n)
		bits++;
	return (bits);
}

void	sort_complex(t_push_swap *ps)
{
	int	bit;
	int	bits;
	int	count;

	bits = count_bits(ps->a.size);
	bit = 0;
	while (bit < bits)
	{
		count = ps->a.size;
		while (count-- > 0)
		{
			if ((ps->a.data[0] >> bit) & 1)
				op_ra(pa);
			else
				op_pb(ps);
		}
		while (ps->b.size > 0)
			op_pa(ps);
		bit++;
	}
}
