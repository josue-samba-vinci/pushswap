/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_last_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-06 12:35:47 by tmattela          #+#    #+#             */
/*   Updated: 2026-05-06 12:35:47 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_pos(t_stack *stack_a)
{
	int		max;
	int		pos;
	int		i;
	t_stack	*current;

	current = stack_a;
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

void	three_sort(t_stack *stack, t_count *count)
{
	int		pos;

	pos = find_max_pos(stack);
	if (pos == 2 && (stack->value > stack->next->value))
		swap(&stack, count, 'a');
	else if (pos == 1)
	{
		reverse_rotate(&stack, count, 'a');
		if ((stack->value > stack->next->value))
			swap(&stack, count, 'a');
	}
	else if (pos == 0)
	{
		rotate(&stack, count, 'a');
		if ((stack->value > stack->next->value))
			swap(&stack, count, 'a');
	}
}
