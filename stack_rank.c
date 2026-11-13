/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack_rank.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 12:10:06 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 13:16:07 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(const t_stack *s)
{
	int	i;

	i = 0;
	while (i + 1 < s->size)
	{
		if (s->data[i] > s->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	compare_int(const void *a, const void *b)
{
	int	ia;
	int	ib;

	ia = *(const int *) a;
	ib = *(const int *) b;
	if (ia < ib)
		return (-1);
	if (ia > ib)
		return (1);
	return (0);
}

static int	rank_of(const int *sorted, int n, int value)
{
	int	lo;
	int	hi;
	int	mid;

	lo = 0;
	hi = n - 1;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (sorted[mid] == value)
			return (mid);
		if (sorted[mid] < value)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return (-1);
}

int	rank_values(int *a, int n)
{
	int	*sorted;
	int	i;

	sorted = ft_calloc(n, sizeof(int));
	if (!sorted)
		return (1);
	i = 0;
	while (i < n)
	{
		sorted[i] = a[i];
		i++;
	}
	qsort(sorted, n, sizeof(int), compare_int);
	i = 0;
	while (i < n)
	{
		a[i] = rank_of(sorted, n, a[i]);
		i++;
	}
	free(sorted);
	return (0);
}
