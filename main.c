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

static void	print_numbers(const t_stack *a)
{
	ft_putstr_fd("[TEST] numbers:", 1);
	while (a)
	{
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(a->value, 1);
		a = a->next;
	}
	ft_putchar_fd('\n', 1);
}

static void	print_test(t_push_swap *ps, int strategy, int bench)
{
	ft_putstr_fd("[TEST] strategy: ", 1);
	ft_putstr_fd(strategy_name(strategy), 1);
	ft_putstr_fd("\n[TEST] bench: ", 1);
	ft_putnbr_fd(bench, 1);
	ft_putstr_fd("\n[TEST] count: ", 1);
	ft_putnbr_fd(stack_size(ps->a), 1);
	ft_putstr_fd("\n[TEST] sorted: ", 1);
	if (stack_is_sorted(ps->a))
		ft_putstr_fd("yes\n", 1);
	else
		ft_putstr_fd("no\n", 1);
	print_numbers(ps->a);
	ft_putstr_fd("[TEST] TODO: tri non implemente\n", 1);
}

int	main(int argc, char **argv)
{
	t_config	cfg;
	t_push_swap	ps;
	int			start;

	if (argc < 2)
		return (0);
	start = parse_flags(argc, argv, &cfg);
	if (start < 0)
		return (print_error());
	ft_memset(&ps, 0, sizeof(ps));
	if (parse_numbers(argc, argv, start, &ps.a))
		return (print_error());
	print_test(&ps, cfg.strategy, cfg.bench);
	stack_free(&ps.a);
	stack_free(&ps.b);
	return (0);
}
