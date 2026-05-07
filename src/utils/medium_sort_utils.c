/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:01:59 by josamba-          #+#    #+#             */
/*   Updated: 2026/05/06 15:02:01 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_max_pos_b(t_stack *stack_b)
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

int	find_chunk_pos(t_stack *stack, int min, int max)
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

void	rotate_to_top(t_stack **stack_a, t_count *count, int index,
		int size)
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

void	advance_chunk(int *min, int *max, int *count, int chunk_size)
{
	*min += chunk_size;
	*max += chunk_size;
	*count = 0;
}
