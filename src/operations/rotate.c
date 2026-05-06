/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:46:50 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/29 17:46:58 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_and_calculate(t_count *count, char c)
{
	if (c == 'a')
	{
		ft_printf(1, "ra\n");
		count->ra++;
		count->total++;
	}
	else if (c == 'b')
	{
		ft_printf(1, "rb\n");
		count->rb++;
		count->total++;
	}
}

void	rotate(t_stack **stack, t_count *count, char c)
{
	int		temp_content;
	t_stack	*current;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	temp_content = (*stack)->value;
	while (current->next != NULL)
	{
		current->value = current->next->value;
		current = current->next;
	}
	current->value = temp_content;
	write_and_calculate(count, c);
}
