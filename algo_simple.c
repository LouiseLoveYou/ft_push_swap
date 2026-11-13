/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algo_simple.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 13:12:04 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 11:51:50 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_highest_val(t_stack *a)
{
	int		higest;
	t_stack	*current;

	higest = a->value;
	current = a;
	while (current != NULL)
	{
		if (current->value > higest)
		{
			higest = current->value;
		}
		current = current->next;
	}
	return (higest);
}

void	sort_three(t_stack **a)
{
	int	higest;

	higest = get_highest_val(*a)
}
