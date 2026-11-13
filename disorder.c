/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   disorder.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 13:12:00 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 13:16:10 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(const t_stack *a)
{
	long long		inversions;
	long long		total;
	const t_stack	*i;
	const t_stack	*j;
	int				n;

	n = stack_size(a);
	inversions = 0;
	total = (long long) n * (n - 1) / 2;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				inversions++;
			j = j->next;
		}
		i = i->next;
	}
	if (total == 0)
		return (0.0);
	return ((double) inversions / (double) total);
}
