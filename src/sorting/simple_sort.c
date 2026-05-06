/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-01 12:19:00 by tmattela          #+#    #+#             */
/*   Updated: 2026-05-01 12:19:00 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *stack_a)
{
	int		min;
	int		pos;
	int		i;
	t_stack	*current;

	current = stack_a;
	min = current->value;
	i = 0;
	pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	int	size;
	int	pos;
	int	rra_count;

	size = stack_size(*stack_a);
	while ((size) > 1)
	{
		pos = find_min_pos(*stack_a);
		if (pos <= size / 2)
		{
			while ((pos-- > 0))
				rotate(stack_a, count, 'a');
		}
		else
		{
			rra_count = size - pos;
			while (rra_count-- > 0)
				reverse_rotate(stack_a, count, 'a');
		}
		push(stack_a, stack_b, count, 'b');
		size--;
	}
	size = stack_size(*stack_b);
	while ((size--) > 0)
		push(stack_b, stack_a, count, 'a');
}

