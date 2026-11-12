/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parsing.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 11:01:00 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/12 13:11:49 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	strategy_from(char *arg)
{
	if (!ft_strncmp(arg, "--simple", 9))
		return (SIMPLE);
	if (!ft_strncmp(arg, "--medium", 9))
		return (MEDIUM);
	if (!ft_strncmp(arg, "--complex", 10))
		return (COMPLEX);
	if (!ft_strncmp(arg, "--adaptive", 11))
		return (ADAPTIVE);
	return (-1);
}

int	parse_flags(int argc, char **argv, t_config *cfg)
{
	int	strategy;
	int	i;

	cfg->strategy = ADAPTIVE;
	cfg->bench = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!ft_strncmp(argv[i], "--bench", 8))
			cfg->bench = 1;
		else
		{
			strategy = strategy_from(argv[i]);
			if (strategy < 0)
				return (-1);
			cfg->strategy = strategy;
		}
		i++;
	}
	return (i);
}

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

static int	has_duplicate(int *a, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (a[i] == a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parse_numbers(int argc, char **argv, int start, int *n)
{
	int	*a;
	int	i;
	int	k;

	*n = count_numbers(argc, argv, start);
	if (*n < 0)
		return (NULL);
	a = (int *) ft_calloc(*n, sizeof(int));
	if (!a)
		return (NULL);
	i = start;
	k = 0;
	while (i < argc && !fill_arg(argv[i], a, &k))
		i++;
	if (i < argc || has_duplicate(a, *n))
	{
		free(a);
		return (NULL);
	}
	return (a);
}
