/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:39:50 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/29 17:40:14 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		length;
	t_stack	*current;

	current = stack;
	length = 0;
	if (current == NULL)
		return (0);
	while (current->next != NULL)
	{
		length++;
		current = current->next;
	}
	length++;
	return (length);
}
