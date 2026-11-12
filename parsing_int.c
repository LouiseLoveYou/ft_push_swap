/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parsing_int.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 13:02:53 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/12 13:02:53 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	skip_sign(const char **s)
{
	int	sign;

	sign = 1;
	if (**s == '+' || **s == '-')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	return (sign);
}

int	parse_int(const char *s, int *out)
{
	long	res;
	int		sign;
	int		digits;

	res = 0;
	sign = skip_sign(&s);
	digits = 0;
	while (ft_isdigit(*s))
	{
		res = res * 10 + (*s++ - '0');
		digits++;
		if (res > (long)INT_MAX + (sign < 0))
			return (1);
	}
	if (digits == 0 || *s != '\0')
		return (1);
	*out = (int)(res * sign);
	return (0);
}
