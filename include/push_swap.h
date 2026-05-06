/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-28 09:42:44 by tmattela          #+#    #+#             */
/*   Updated: 2026-04-28 09:42:44 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "../src/utils/printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_count
{
	int	ra;
	int	rb;
	int	rr;
	int	pa;
	int	pb;
	int	sa;
	int	sb;
	int	ss;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_count;

typedef struct s_global
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_count	count;
	int		bench;
	int		algo;
}	t_global;

typedef struct s_chunk
{
	int	size;
	int	min;
	int	max;
	int	count;
}	t_chunk;

int		ft_isdigit(int c);
int		parse_arguments(int i, char **argv, t_global *global);
int		ft_atoi(const char *nptr);
int		stack_size(t_stack *stack);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		parse_flags(t_global *global, char **argv, int argc);
int		ft_sqrt(int nb);
int		find_max_pos_b(t_stack *stack_b);
int		find_chunk_pos(t_stack *stack, int min, int max);
int		ft_sqrt(int nb);
int		find_max_pos_b(t_stack *stack_b);
int		find_chunk_pos(t_stack *stack, int min, int max);
int		*extract(t_stack **stack);
char	**ft_split(char const *s, char c);
t_stack	*ft_lstnew(int value);
t_stack	*ft_lstlast(t_stack *lst);
float	compute_disorder(t_stack *stack_a);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	reverse_rotate(t_stack **stack, t_count *count, char c);
void	reverse_rotate_a_b(t_stack **stack_a, t_stack **stack_b,
			t_count *count);
void	rotate(t_stack **stack, t_count *count, char c);
void	rotate_a_b(t_stack **stack_a, t_stack **stack_b, t_count *count);
void	push(t_stack **stack_a, t_stack **stack_b, t_count *count, char c);
void	swap(t_stack **stack, t_count *count, char c);
void	swap_a_b(t_stack *stack_a, t_stack *stack_b, t_count *count);
void	complex_sort(t_stack **stack_a, t_stack **stack_b, t_count *count);
void	medium_sort(t_stack **stack_a, t_stack **stack_b, t_count *count);
void	simple_sort(t_stack **stack_a, t_stack **stack_b, t_count *count);
void	*ft_memset(void *b, int c, size_t len);
void	three_sort(t_stack *stack, t_count *count);
void	print_bench(t_count *count, float disorder, int strat);
void	sort_tab(int *tab, int size);
void	index_stack(t_stack **stack);
void	rotate_to_top(t_stack **stack_a, t_count *count, int index, 
	int size);
void	advance_chunk(int *min, int *max, int *count, int chunk_size);

#endif
