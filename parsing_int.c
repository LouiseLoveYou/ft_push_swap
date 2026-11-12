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

static int	parse_digits(const char *s, int len, long *res, long limit)
{
	int	i;

	i = 0;
	while (i < len && ft_isdigit(s[i]))
	{
		if (*res > (limit - (s[i] - '0')) / 10)
			return (1);
		*res = *res * 10 + (s[i] - '0');
		i++;
	}
	if (i != len)
		return (1);
	return (0);
}

int	parse_int(const char *s, int *out, int len)
{
	long	res;
	long	limit;
	int		sign;

	res = 0;
	sign = 1;
	if (len > 0 && s[0] == '-')
		sign = -1;
	if (len > 0 && (s[0] == '+' || s[0] == '-'))
	{
		s++;
		len--;
	}
	if (len <= 0)
		return (1);
	limit = (long)INT_MAX + (sign < 0);
	if (parse_digits(s, len, &res, limit))
		return (1);
	*out = (int)(res * sign);
	return (0);
}
