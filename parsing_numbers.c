/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parsing_numbers.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 13:02:53 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/12 13:02:53 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

static int	count_words(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (!is_space(s[i]) && (i == 0 || is_space(s[i - 1])))
			count++;
		i++;
	}
	return (count);
}

int	count_numbers(int argc, char **argv, int start)
{
	int	i;
	int	count;
	int	words;

	count = 0;
	i = start;
	while (i < argc)
	{
		words = count_words(argv[i]);
		if (words == 0)
			return (-1);
		count += words;
		i++;
	}
	if (count == 0)
		return (-1);
	return (count);
}

int	fill_arg(char *arg, t_stack **a)
{
	int	j;
	int	start;
	int	value;

	j = 0;
	while (arg[j])
	{
		while (is_space(arg[j]))
			j++;
		if (!arg[j])
			break ;
		start = j;
		while (arg[j] && !is_space(arg[j]))
			j++;
		if (parse_int(arg + start, &value, j - start))
			return (1);
		if (stack_add_back(a, value))
			return (1);
	}
	return (0);
}
