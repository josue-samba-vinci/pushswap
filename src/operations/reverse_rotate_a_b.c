/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:47:42 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/29 17:47:46 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_and_calculate(t_count *count)
{
	ft_printf(1, "rrr\n");
	count->rrr++;
	count->total++;
}

void	reverse_rotate_a_b(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	reverse_rotate(stack_a, count, ' ');
	reverse_rotate(stack_b, count, ' ');
	write_and_calculate(count);
}
