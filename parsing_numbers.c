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

	count = 0;
	i = start;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (-1);
		count += count_words(argv[i]);
		i++;
	}
	if (count == 0)
		return (-1);
	return (count);
}

int	fill_arg(char *arg, int *a, int *k)
{
	char	buf[12];
	int		j;
	int		len;

	j = 0;
	while (arg[j])
	{
		while (is_space(arg[j]))
			j++;
		len = 0;
		while (arg[j] && !is_space(arg[j]) && len < 11)
			buf[len++] = arg[j++];
		if (len == 0)
			break ;
		if (arg[j] && !is_space(arg[j]))
			return (1);
		buf[len] = '\0';
		if (parse_int(buf, &a[*k]))
			return (1);
		(*k)++;
	}
	return (0);
}
