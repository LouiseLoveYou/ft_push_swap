/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 13:11:51 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 11:15:57 by tobillet        ###   ########.fr        */
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
