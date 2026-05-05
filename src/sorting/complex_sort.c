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

# include "push_swap.h"

int	*extract(t_stack **stack)
{
	int	size;
	int	i;
	int	*tab;
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
		while (j < size - 1 -i)
		{
			if (tab[j] > tab[j+1])
			{
				temp = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	index_stack(t_stack **stack)
{
	int	*tab;
	int	size;
	int	i;
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
				break;
			}
			i++;
		}
		current = current->next;
	}
	free(tab);
}

int	get_max_bits(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}
//Thomas j ai pas encore check le main correctement mais si mon complex_sort
//est appele alors qu il y a que 1 element ou 0 element dans la stack, ca va faire 
//crash get_max_bits avec le size-1 quand j appelle la fonction
void	complex_sort(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	int size;
	int	bits;
	int	i;
	int	max_bits;
	
	bits = 0;
	size = stack_size(*stack_a);
	max_bits = get_max_bits(size - 1);
	while (bits < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((((*stack_a)->value >> bits) & 1) == 1)
				rotate(stack_a, 'a');
			else 
				push(stack_b, stack_a, count, 'a');
			i++;
		}
		while (*stack_b)
			push(stack_a, stack_b, count, 'b');
		bits++;
	}
}
