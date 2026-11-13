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

double	compute_disorder(const int *a, int n)
{
	long long	inversions;
	long long	total;
	int			i;
	int			j;

	inversions = 0;
	total = (long long) n * (n - 1) / 2;
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (a[i] > a[j])
				inversions++;
			j++;
		}
		i++;
	}
	if (total == 0)
		return (0.0);
	return ((double) inversions / (double) total);
}
