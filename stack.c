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

int	stack_init(t_stack *s, int cap)
{
	s->data = ft_calloc(cap, sizeof(int));
	if (!s->data)
		return (1);
	s->size = 0;
	s->cap = cap;
	return (0);
}

void	stack_free(t_stack *s)
{
	free(s->data);
	s->data = NULL;
	s->size = 0;
	s->cap = 0;
}

int	stack_push(t_stack *s, int value)
{
	int	i;

	if (s->size >= s->cap)
		return (1);
	i = s->size;
	while (i > 0)
	{
		s->data[i] = s->data[i - 1];
		i--;
	}
	s->data[0] = value;
	s->size++;
	return (0);
}

int	stack_pop(t_stack *s, int *value)
{
	int	i;

	if (s->size <= 0)
		return (1);
	*value = s->data[0];
	i = 1;
	while (i < s->size)
	{
		s->data[i - 1] = s->data[i];
		i++;
	}
	s->size--;
	return (0);
}

void	stack_fill(t_stack *s, const int *values, int n)
{
	int	i;

	i = n - 1;
	while (i >= 0)
	{
		stack_push(s, values[i]);
		i--;
	}
}
