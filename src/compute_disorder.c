/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-29 10:36:49 by tmattela          #+#    #+#             */
/*   Updated: 2026-04-29 10:36:49 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *stack_a, int size)
{
	int		*arr;
	int		i;
	t_stack	*current;

	i = 0;
	current = stack_a;
	arr = malloc(sizeof(int) * (size));
	if (!arr)
		return (NULL);
	while (current != NULL)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	return (arr);
}

static float	count_mistakes(int *arr, int size)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((float)mistakes / total_pairs);
}

float	compute_disorder(t_stack *stack_a)
{
	int		*arr;
	int		size;
	float	disorder;

	size = stack_size(stack_a);
	arr = stack_to_array(stack_a, size);
	if (!arr)
		return (0.0);
	disorder = count_mistakes(arr, size);
	free(arr);
	return (disorder);
}
