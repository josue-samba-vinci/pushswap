/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-01 12:19:00 by tmattela          #+#    #+#             */
/*   Updated: 2026-05-01 12:19:00 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void    print_stack(t_stack *stack, char *name);
static int	find_min_pos(t_stack *stack_a)
{
	int		min;
	int		pos;
	int		i;
	t_stack	*current;

	current = stack_a;
	min = current->value;
	i = 0;
	pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	int	size;
	int	pos;
	int	rra_count;

	ft_printf(1, "Simple sorting\n");
	size = stack_size(*stack_a);
	while ((size) > 1)
	{
		pos = find_min_pos(*stack_a);
		if (pos <= size / 2)
		{
			while ((pos-- > 0))
				rotate(stack_a, count, 'a');
		}
		else
		{
			rra_count = size - pos;
			while (rra_count-- > 0)
				reverse_rotate(stack_a, count, 'a');
		}
		push(stack_a, stack_b, count, 'b');
		size--;
	}
	size = stack_size(*stack_b);
	while ((size--) > 0)
		push(stack_b, stack_a, count, 'a');
}
// #include <stdio.h>
// void    print_stack(t_stack *stack, char *name)
// {
//     t_stack *current;

//     printf("Stack %s (top→bot): ", name);
//     current = stack;
//     while (current)
//     {
//         printf("[%d] ", current->value);
//         current = current->next;
//     }
//     printf("\n");
// }
// t_stack *new_node(int value)
// {
//     t_stack *node;

//     node = malloc(sizeof(t_stack));
//     node->value = value;
//     node->next = NULL;
//     return (node);
// }
// int main(void)
// {
// 	t_stack *stack_a;
//     t_stack *stack_b;

//     // Stack hardcodée : 3 → 5 → 1 → 4 → 2  (top → bot)
//     stack_a = new_node(3);
//     stack_a->next = new_node(5);
//     stack_a->next->next = new_node(1);
//     stack_a->next->next->next = new_node(4);
//     stack_a->next->next->next->next = new_node(2);
//     stack_b = NULL;

//     printf("=== État initial ===\n");
//     print_stack(stack_a, "A");
//     printf("\n=== Début du tri ===\n\n");

//     simple_sort(&stack_a, &stack_b);

//     printf("=== État final ===\n");
//     print_stack(stack_a, "A");
//     print_stack(stack_b, "B");

//     return (0);
// }
