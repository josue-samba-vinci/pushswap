/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:45:26 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/29 17:45:31 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_and_calculate(t_count *count, char c)
{
	if (c == 'a')
	{
		ft_printf(1, "sa\n");
		count->sa++;
		count->total++;
	}
	else if (c == 'b')
	{
		ft_printf(1, "sb\n");
		count->sb++;
		count->total++;
	}
}

void	swap(t_stack **stack, t_count *count, char c)
{
	int	temp_content;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	temp_content = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp_content;
	write_and_calculate(count, c);
}
