/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 13:12:02 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 13:46:19 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*strategy_name(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("Simple");
	if (strategy == MEDIUM)
		return ("Medium");
	if (strategy == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

static void	put_long_fd(long value, int fd)
{
	char	c;

	if (value >= 10)
		put_long_fd(value / 10, fd);
	c = (char)('0' + value % 10);
	write(fd, &c, 1);
}

static void	put_disorder(double disorder)
{
	long	hundredths;
	long	integer;
	long	decimal;

	hundredths = (long)(disorder * 10000.0 + 0.5);
	integer = hundredths / 100;
	decimal = hundredths % 100;
	put_long_fd(integer, 2);
	ft_putchar_fd('.', 2);
	if (decimal < 10)
		ft_putchar_fd('0', 2);
	put_long_fd(decimal, 2);
	ft_putchar_fd('%', 2);
}

static void	print_swap_counts(const t_counts *counts)
{
	ft_putstr_fd("\n[bench] sa: ", 2);
	put_long_fd(counts->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	put_long_fd(counts->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	put_long_fd(counts->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	put_long_fd(counts->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	put_long_fd(counts->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	put_long_fd(counts->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	put_long_fd(counts->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	put_long_fd(counts->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	put_long_fd(counts->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	put_long_fd(counts->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	put_long_fd(counts->rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench(const t_push_swap *ps, t_strategy strategy)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	put_disorder(ps->disorder);
	ft_putstr_fd("\n[bench] strategy: ", 2);
	ft_putstr_fd(strategy_name(strategy), 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	put_long_fd(ps->counts.total, 2);
	print_swap_counts(&ps->counts);
}
