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
// 	t_stack *b = new_node(5);
//     b->next = new_node(6);
//     b->next->next = new_node(7);
//     b->next->next->next = new_node(8);

//     print_stack(a, "A avant");
// 	print_stack(b, "B avant");
//     rotate_a_b(&a,&b);
//     print_stack(a, "A après");
//     print_stack(b, "B après");
//     return 0;
// }
