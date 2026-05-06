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

#include "push_swap.h"

void	push_b(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	int		size;
	int		index;
	t_chunk	chunk;

	size = stack_size(*stack_a);
	chunk.size = ft_sqrt(size);
	chunk.min = 0;
	chunk.max = chunk.size;
	chunk.count = 0;
	while (*stack_a)
	{
		index = find_chunk_pos(*stack_a, chunk.min, chunk.max);
		if (index >= 0)
		{
			rotate_to_top(stack_a, count, index, size);
			push(stack_a, stack_b, count, 'b');
			size--;
			chunk.count++;
		}
		if (chunk.count == chunk.size || index < 0)
			advance_chunk(&chunk.min, &chunk.max, &chunk.count, chunk.size);
	}
}

void	push_a(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	int	pos_max;
	int	rotation;
	int	size;

	while (*stack_b)
	{
		size = stack_size(*stack_b);
		pos_max = find_max_pos_b(*stack_b);
		if (pos_max > size / 2)
		{
			rotation = size - pos_max;
			while (rotation > 0)
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
