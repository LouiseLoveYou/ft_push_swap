/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 10:51:46 by tobillet         #+#    #+#              */
/*   Updated: 2026/11/13 10:51:46 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
}	t_config;

typedef struct s_stack
{
	int	*data;
	int	size;
	int	cap;
}	t_stack;

typedef struct s_counts
{
	long	sa;
	long	sb;
	long	ss;
	long	pa;
	long	pb;
	long	ra;
	long	rb;
	long	rr;
	long	rra;
	long	rrb;
	long	rrr;
	long	total;
}	t_counts;

typedef struct s_push_swap
{
	t_stack		a;
	t_stack		b;
	t_counts	counts;
	double		disorder;
}	t_push_swap;

int	print_error(void);
int	parse_flags(int argc, char **argv, t_config *cfg);
int	*parse_numbers(int argc, char **argv, int start, int *n);
int	count_numbers(int argc, char **argv, int start);
int	fill_arg(char *arg, int *a, int *k);
int	parse_int(const char *s, int *out, int len);

int		stack_init(t_stack *s, int cap);
void	stack_free(t_stack *s);
int		stack_push(t_stack *s, int value);
int		stack_pop(t_stack *s, int *value);
void	stack_fill(t_stack *s, const int *values, int n);
int		stack_is_sorted(const t_stack *s);
int		rank_values(int *a, int n);

double	compute_disorder(const int *a, int n);

void	print_op(char *name);
void	rotate_down(t_stack *s);
void	op_sa(t_push_swap *ps);
void	op_sb(t_push_swap *ps);
void	op_ss(t_push_swap *ps);
void	op_pa(t_push_swap *ps);
void	op_pb(t_push_swap *ps);
void	op_ra(t_push_swap *ps);
void	op_rb(t_push_swap *ps);
void	op_rr(t_push_swap *ps);
void	op_rra(t_push_swap *ps);
void	op_rrb(t_push_swap *ps);
void	op_rrr(t_push_swap *ps);

void	sort_simple(t_push_swap *ps);
void	sort_medium(t_push_swap *ps);
void	sort_complex(t_push_swap *ps);
void	sort_adaptive(t_push_swap *ps);
void	run_strategy(t_push_swap *ps, t_strategy strategy);

void	print_bench(const t_push_swap *ps, t_strategy strategy);

#endif
