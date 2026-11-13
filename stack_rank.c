/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack_rank.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 12:10:06 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 13:48:58 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(const t_stack *s)
{
	while (s && s->next)
	{
		if (s->value > s->next->value)
			return (0);
		s = s->next;
	}
	return (1);
}

int	rank_values(t_stack *s)
{
	t_stack	*copy;
	t_stack	*current;
	t_stack	*reference;
	int		rank;

	copy = stack_dup(s);
	if (!copy && s)
		return (1);
	current = s;
	while (current)
	{
		rank = 0;
		reference = copy;
		while (reference)
		{
			if (reference->value < current->value)
				rank++;
			reference = reference->next;
		}
		current->value = rank;
		current = current->next;
	}
	stack_free(&copy);
	return (0);
}
