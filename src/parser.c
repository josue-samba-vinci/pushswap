/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-28 09:51:09 by tmattela          #+#    #+#             */
/*   Updated: 2026-04-28 09:51:09 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	parsing_data(char *argv, int *res)
{
	int	i;

	i = 0;
	if (!argv[i])
		return (0);
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 0)
			return (0);
		i++;
	}
	*res = ft_atoi(argv);
	return (1);
}

static int	check_duplicates(t_stack *stack_a, int nb)
{
	t_stack	*current;

	current = stack_a;
	while (current != NULL)
	{
		if (nb == current->value)
			return (0);
		current = current->next;
	}
	return (1);
}

static int	valid_arguments(t_stack **stack_a, char **argv)
{
	int		i;
	int		res;

	i = 0;
	while (argv[i])
	{
		if (parsing_data(argv[i], &res) == 0
			|| check_duplicates(*stack_a, res) == 0)
		{
			free_stack(stack_a);
			ft_printf(2, "Error\n");
			return (0);
		}
		ft_lstadd_back(stack_a, ft_lstnew(res));
		i++;
	}
	return (1);
}

int	parse_arguments(int i, char **argv, t_global *global)
{
	char		**tab;

	if (!argv[i])
	{
		ft_printf(2, "Error\n");
		return (0);
	}
	while (argv[i])
	{
		tab = ft_split(argv[i], ' ');
		if (valid_arguments(&global->stack_a, tab) == 0)
		{
			free_split(tab);
			return (0);
		}
		free_split(tab);
		i++;
	}
	return (1);
}
