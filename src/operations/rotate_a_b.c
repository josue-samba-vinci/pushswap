/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:48:26 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/29 17:48:31 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_and_calculate(t_count *count)
{
	ft_printf(1, "rr\n");
	count->rr++;
	count->total++;
}

void	rotate_a_b(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	rotate(stack_a, count, ' ');
	rotate(stack_b, count, ' ');
	write_and_calculate(count);
}
