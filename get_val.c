/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_val.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 14:39:50 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/16 10:49:06 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_val_position(t_stack *a, int target_val)
{
	int		pos;
	t_stack	*current;

	pos = 0;
	current = a;
	while (current != NULL)
	{
		if (current->value == target_val)
			return (pos);
		pos++;
		current = current->next;
	}
	return (pos);
}

int	get_lowest_val(t_stack *a)
{
	int		lowest;
	t_stack	*current;

	lowest = a->value;
	current = a;
	while (current != NULL)
	{
		if (current->value < lowest)
			lowest = current->value;
		current = current->next;
	}
	return (lowest);
}

int	get_highest_val(t_stack *a)
{
	int		highest;
	t_stack	*current;

	highest = a->value;
	current = a;
	while (current != NULL)
	{
		if (current->value > highest)
			highest = current->value;
		current = current->next;
	}
	return (highest);
}
