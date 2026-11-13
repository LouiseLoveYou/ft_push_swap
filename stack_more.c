/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack_more.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 13:50:17 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 14:13:40 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_add_back(t_stack **s, int value)
{
	t_stack	*node;
	t_stack	*last;

	node = stack_new(value);
	if (!node)
		return (1);
	if (!*s)
	{
		*s = node;
		return (0);
	}
	last = stack_last(*s);
	last->next = node;
	return (0);
}

int	stack_pop(t_stack **s, int *value)
{
	t_stack	*node;

	if (!*s)
		return (1);
	node = *s;
	*value = node->value;
	*s = node->next;
	free(node);
	return (0);
}

int	stack_size(const t_stack *s)
{
	int	size;

	size = 0;
	while (s)
	{
		size++;
		s = s->next;
	}
	return (size);
}
