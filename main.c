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

static int	init_push_swap(t_push_swap *ps, int argc, char **argv, int start)
{
	ps->a = NULL;
	ps->b = NULL;
	if (parse_numbers(argc, argv, start, &ps->a))
		return (1);
	if (rank_values(ps->a))
	{
		stack_free(&ps->a);
		return (1);
	}
	ft_bzero(&ps->counts, sizeof(t_counts));
	ps->disorder = compute_disorder(ps->a);
	return (0);
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
	if (init_push_swap(&ps, argc, argv, start))
		return (print_error());
	if (!stack_is_sorted(ps.a))
		run_strategy(&ps, cfg.strategy);
	if (cfg.bench)
		print_bench(&ps, cfg.strategy);
	stack_free(&ps.a);
	stack_free(&ps.b);
	return (0);
}
