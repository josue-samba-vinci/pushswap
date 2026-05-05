/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:42:41 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/29 17:42:43 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_and_calculate(t_count *count, char c)
{
	if (c == 'a')
	{
		ft_printf(1, "rra\n");
		count->rra++;
		count->total++;
	}
	else if (c == 'b')
	{
		ft_printf(1, "rrb\n");
		count->rrb++;
		count->total++;
	}
}

void	reverse_rotate(t_stack **stack, t_count *count, char c)
{
	t_stack	*top;
	t_stack	*before_bottom;
	t_stack	*bottom;
	t_stack	*current;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	top = *stack;
	current = *stack;
	while (current->next->next != NULL)
		current = current->next;
	before_bottom = current;
	bottom = current->next;
	*stack = bottom;
	bottom->next = top;
	before_bottom->next = NULL;
	write_and_calculate(count, c);
}

// t_stack *new_node(int value)
// {
//     t_stack *node = malloc(sizeof(t_stack));
//     node->value = value;
//     node->next = NULL;
//     return node;
// }

// void print_stack(t_stack *stack, char *name)
// {
//     printf("%s: ", name);
//     while (stack)
//     {
//         printf("%d ", stack->value);
//         stack = stack->next;
//     }
//     printf("\n");
// }

// int main()
// {
//     t_stack *a = new_node(1);
//     a->next = new_node(2);
//     a->next->next = new_node(3);
//     a->next->next->next = new_node(4);

//     t_stack *b = new_node(5);
//     b->next = new_node(6);
//     b->next->next = new_node(7);
//     b->next->next->next = new_node(8);

//     print_stack(a, "A avant");
//     reverse_rotate(&a);
//     print_stack(a, "A après");
//     return 0;
// }
