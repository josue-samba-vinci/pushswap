/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:42:06 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/29 17:42:09 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_and_calculate(t_count *count)
{
	ft_printf(1, "ss\n");
	count->ss++;
	count->total++;
}

void	swap_a_b(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	swap(stack_a, count, ' ');
	swap(stack_b, count, ' ');
	write_and_calculate(count);
}
