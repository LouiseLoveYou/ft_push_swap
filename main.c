/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 13:36:58 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 13:37:15 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_push_swap(t_push_swap *ps, int *values, int n)
{
	ft_bzero(&ps->counts, sizeof(t_counts));
	ps->disorder = compute_disorder(values, n);
	if (stack_init(&ps->a, n))
		return (1);
	if (stack_init(&ps->b, n))
	{
		stack_free(&ps->a);
		return (1);
	}
	stack_fill(&ps->a, values, n);
	return (0);
}

static int	parse_input(int argc, char **argv, t_config *cfg, int **values)
{
	int	start;
	int	n;

	start = parse_flags(argc, argv, cfg);
	if (start < 0)
		return (-1);
	*values = parse_numbers(argc, argv, start, &n);
	if (!*values)
		return (-1);
	if (rank_values(*values, n))
	{
		free(*values);
		return (-1);
	}
	return (n);
}

int	main(int argc, char **argv)
{
	t_config	cfg;
	t_push_swap	ps;
	int			*values;
	int			n;

	if (argc < 2)
		return (0);
	n = parse_input(argc, argv, &cfg, &values);
	if (n < 0)
		return (print_error());
	if (init_push_swap(&ps, values, n))
	{
		free(values);
		return (print_error());
	}
	if (!stack_is_sorted(&ps.a))
		run_strategy(&ps, cfg.strategy);
	if (cfg.bench)
		print_bench(&ps, cfg.strategy);
	stack_free(&ps.a);
	stack_free(&ps.b);
	free(values);
	return (0);
}
