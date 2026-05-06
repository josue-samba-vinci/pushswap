/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:51:41 by josamba-          #+#    #+#             */
/*   Updated: 2026/05/05 22:51:50 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}
//ATTENTION check le main correctement mais si complex_sort
//est appele alors qu il y a que 1 element ou 0 element dans la stack, ca va faire
//crash get_max_bits avec le size-1 quand j appelle la fonction

void	complex_sort(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	int	size;
	int	bits;
	int	i;
	int	max_bits;

	index_stack(stack_a);
	bits = 0;
	size = stack_size(*stack_a);
	max_bits = get_max_bits(size - 1);
	while (bits < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((((*stack_a)->value >> bits) & 1) == 1) // 000100 
				rotate(stack_a, count, 'a');
			else
				push(stack_a, stack_b, count, 'b');
			i++;
		}
		while (*stack_b)
			push(stack_b, stack_a, count, 'a');
		bits++;
	}
}
