/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 23:22:19 by josamba-          #+#    #+#             */
/*   Updated: 2026/05/05 23:22:24 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while ((i + 1) * (i + 1) <= nb)
		i++;
	return (i);
}
static int	find_max_pos_b(t_stack *stack_b)
{
	int		max;
	int		pos;
	int		i;
	t_stack	*current;

	current = stack_b;
	max = current->value;
	i = 0;
	pos = 0;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

static int	find_chunk_pos(t_stack *stack, int min, int max)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value >= min && stack->value < max)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

static void	rotate_to_top(t_stack **stack_a, t_count *count, int index, int size)
{
	int	rotation;

	if (index > size / 2)
	{
		rotation = size - index;
		while (rotation-- > 0)
			reverse_rotate(stack_a, count, 'a');
	}
	else
	{
		while (index-- > 0)
			rotate(stack_a, count, 'a');
	}
}

static void	advance_chunk(int *min, int *max, int *count, int chunk_size)
{
	*min += chunk_size;
	*max += chunk_size;
	*count = 0;
}

void	push_b(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	int	size;
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	chunk_count;
	int	index;

	size = stack_size(*stack_a);
	chunk_size = ft_sqrt(size);
	chunk_min = 0;
	chunk_max = chunk_size;
	chunk_count = 0;
	while (*stack_a)
	{
		index = find_chunk_pos(*stack_a, chunk_min, chunk_max);
		if (index >= 0)
		{
			rotate_to_top(stack_a, count, index, size);
			push(stack_a, stack_b, count, 'b');
			size--;
			chunk_count++;
		}
		if (chunk_count == chunk_size || index < 0)
			advance_chunk(&chunk_min, &chunk_max, &chunk_count, chunk_size);
	}
}

void push_a(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	int	pos_max;
	int	rotation;
	int size;

	while (*stack_b)
	{
		size = stack_size(*stack_b);
		pos_max = find_max_pos_b(*stack_b);
		if (pos_max > size / 2)
		{
			rotation = size - pos_max;
			while(rotation > 0)
			{
				reverse_rotate(stack_b, count, 'b');
				rotation--;
			}
		}
		else
		{
			while (pos_max-- > 0)
				rotate(stack_b, count, 'b');
		}
		push(stack_b, stack_a, count, 'a');
	}
}

void	medium_sort(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	index_stack(stack_a);
	push_b(stack_a, stack_b, count);
	push_a(stack_a, stack_b, count);
}
