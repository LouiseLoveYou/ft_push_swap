/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 12:20:00 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/12 13:02:53 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*strategy_name(int strategy)
{
	if (strategy == SIMPLE)
		return ("simple");
	if (strategy == MEDIUM)
		return ("medium");
	if (strategy == COMPLEX)
		return ("complex");
	return ("adaptive");
}

static int	is_sorted(int *a, int n)
{
	int	i;

	i = 0;
	while (i + 1 < n)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	print_numbers(int *a, int n)
{
	int	i;

	ft_putstr_fd("[TEST] numbers:", 1);
	i = 0;
	while (i < n)
	{
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(a[i], 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

static void	print_test(int *a, int n, int strategy, int bench)
{
	ft_putstr_fd("[TEST] strategy: ", 1);
	ft_putstr_fd(strategy_name(strategy), 1);
	ft_putstr_fd("\n[TEST] bench: ", 1);
	ft_putnbr_fd(bench, 1);
	ft_putstr_fd("\n[TEST] count: ", 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd("\n[TEST] sorted: ", 1);
	if (is_sorted(a, n))
		ft_putstr_fd("yes\n", 1);
	else
		ft_putstr_fd("no\n", 1);
	print_numbers(a, n);
	ft_putstr_fd("[TEST] TODO: tri non implemente\n", 1);
}

int	main(int argc, char **argv)
{
	t_config	cfg;
	int			*a;
	int			n;
	int			start;

	if (argc < 2)
		return (0);
	start = parse_flags(argc, argv, &cfg);
	if (start < 0)
		return (print_error());
	a = parse_numbers(argc, argv, start, &n);
	if (!a)
		return (print_error());
	print_test(a, n, cfg.strategy, cfg.bench);
	free(a);
	return (0);
}
