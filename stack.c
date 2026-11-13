/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 13:11:51 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 11:53:01 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

t_stack	*stack_last(t_stack *s)
{
	while (s && s->next)
		s = s->next;
	return (s);
}

t_stack	*stack_dup(const t_stack *s)
{
	t_stack	*copy;

	copy = NULL;
	while (s)
	{
		if (stack_add_back(&copy, s->value))
		{
			stack_free(&copy);
			return (NULL);
		}
		s = s->next;
	}
	return (copy);
}

void	stack_free(t_stack **s)
{
	t_stack	*next;

	while (*s)
	{
		next = (*s)->next;
		free(*s);
		*s = next;
	}
}

int	stack_push(t_stack **s, int value)
{
	t_stack	*node;

	node = stack_new(value);
	if (!node)
		return (1);
	node->next = *s;
	*s = node;
	return (0);
}
