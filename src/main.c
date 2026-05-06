/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-29 10:37:05 by tmattela          #+#    #+#             */
/*   Updated: 2026-04-29 10:37:05 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./utils/printf/ft_printf.h"

static int	is_sorted(t_stack *stack_a)
{
	int		min;
	t_stack	*current;

	if (!stack_a)
		return (0);
	current = stack_a;
	min = current->value;
	while (current)
	{
		if (current->value < min)
		{
			return (1);
		}
		min = current->value;
		current = current->next;
	}
	return (0);
}

static void	launch_algo(t_global *global, float disorder)
{
	if (global->algo == 1)
		simple_sort(&global->stack_a, &global->stack_b, &global->count);
	else if (global->algo == 2)
		medium_sort(&global->stack_a, &global->stack_b, &global->count);
	else if (global->algo == 3)
		complex_sort(&global->stack_a, &global->stack_b, &global->count);
	else if (global->algo == 4 || global->algo == 0)
	{
		if (disorder < 0.2)
			simple_sort(&global->stack_a, &global->stack_b, &global->count);
		else if (disorder >= 0.2 && disorder < 0.5)
			medium_sort(&global->stack_a, &global->stack_b, &global->count);
		else if (disorder >= 0.5)
			complex_sort(&global->stack_a, &global->stack_b, &global->count);
	}
}

int	main(int argc, char **argv)
{
	t_global	global;
	int			i;
	float		disorder;

	disorder = 0;
	ft_memset(&global, 0, sizeof(t_global));
	if (argc == 1)
		return (0);
	i = parse_flags(&global, argv, argc);
	if (parse_arguments(i, argv, &global) == 0
		|| is_sorted(global.stack_a) == 0)
		return (0);
	if (global.algo == 4 || global.algo == 0 || global.bench == 1)
		disorder = compute_disorder(global.stack_a);
	if (stack_size(global.stack_a) > 3)
		launch_algo(&global, disorder);
	else
		three_sort(global.stack_a, &global.count);
	if (global.bench == 1)
		print_bench(&global.count, disorder, global.algo);
}
