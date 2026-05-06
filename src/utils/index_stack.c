/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 23:22:46 by josamba-          #+#    #+#             */
/*   Updated: 2026/05/05 23:22:50 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*extract(t_stack **stack)
{
	int		size;
	int		i;
	int		*tab;
	t_stack	*current;

	i = 0;
	size = stack_size(*stack);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	current = *stack;
	while (current)
	{
		tab[i] = current->value;
		current = current->next;
		i++;
	}
	return (tab);
}

void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	index_stack(t_stack **stack)
{
	int		*tab;
	int		size;
	int		i;
	t_stack	*current;

	i = 0;
	size = stack_size(*stack);
	tab = extract(stack);
	sort_tab(tab, size);
	current = *stack;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] == current->value)
			{
				current->value = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(tab);
}
