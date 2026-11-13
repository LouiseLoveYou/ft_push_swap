/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisella <kisella@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:12:07 by kisella           #+#    #+#             */
/*   Updated: 2026/11/13 16:33:31 by kisella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks_to_b(t_push_swap *ps, int range)
{
	int	i;

	i = 0;
	while (ps->a != NULL)
	{
		if (ps->a->value <= i)
		{
			op_pb(ps);
			op_rb(ps);
			i++;
		}
		else if (ps->a->value <= i + range)
		{
			op_pb(ps);
			i++;
		}
		else
			op_ra(ps);
	}
}
