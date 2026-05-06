/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-29 10:55:59 by tmattela          #+#    #+#             */
/*   Updated: 2026-04-29 10:55:59 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_and_calculate(t_count *count, char c)
{
	if (c == 'a')
	{
		ft_printf(1, "pa\n");
		count->pa++;
		count->total++;
	}
	else if (c == 'b')
	{
		ft_printf(1, "pb\n");
		count->pb++;
		count->total++;
	}
}

void	push(t_stack **stack_b, t_stack **stack_a, t_count *count, char c)
{
	t_stack	*save_a;
	t_stack	*save_b_next;

	if (*stack_b == NULL)
		return ;
	save_b_next = (*stack_b)->next;
	save_a = *stack_a;
	*stack_a = *stack_b;
	(*stack_a)->next = save_a;
	*stack_b = save_b_next;
	write_and_calculate(count, c);
}
