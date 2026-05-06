/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-04 09:58:42 by tmattela          #+#    #+#             */
/*   Updated: 2026-05-04 09:58:42 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_flags(char *s, t_global *global)
{
	if (ft_strncmp(s, "--simple", 8) == 0)
		global->algo = 1;
	else if (ft_strncmp(s, "--medium", 8) == 0)
		global->algo = 2;
	else if (ft_strncmp(s, "--complex", 9) == 0)
		global->algo = 3;
	else if (ft_strncmp(s, "--adaptative", 10) == 0)
		global->algo = 4;
}

int	parse_flags(t_global *global, char **argv, int argc)
{
	int	i;

	i = 1;
	if (ft_strncmp(argv[i], "--bench", 7) == 0)
	{
		global->bench++;
		i++;
	}
	if (argc > 2 && ft_strncmp(argv[i], "--", 2) == 0)
	{
		handle_flags(argv[i], global);
		i++;
	}
	return (i);
}

static char	*get_strategy(int strat, float disorder)
{
	if (strat == 1)
		return ("Simple / O(n²)");
	if (strat == 2)
		return ("Medium / O(n√n)");
	if (strat == 3)
		return ("Complex / O(n log n)");
	if (disorder < 0.2)
		return ("Adaptive / O(n²)");
	if (disorder < 0.5)
		return ("Adaptive / O(n√n)");
	return ("Adaptive / O(n log n)");
}

void	print_bench(t_count *count, float disorder, int strat)
{
	int	percentage;

	percentage = disorder * 100;
	ft_printf(2, "[bench] Disorder     : %d.00%\n", percentage);
	ft_printf(2, "[bench] Strategy     : %s\n", get_strategy(strat, disorder));
	ft_printf(2, "[bench] Total ops    : %d\n", count->total);
	ft_printf(2, "[bench] ra: %d  rb: %d  rr: %d\n", count->ra,
		count->rb, count->rr);
	ft_printf(2, "[bench] pa: %d  pb: %d\n", count->pa, count->pb);
	ft_printf(2, "[bench] sa: %d  sb: %d  ss: %d\n", count->sa,
		count->sb, count->ss);
	ft_printf(2, "[bench] rra:%d rrb: %d rrr:%d\n", count->rra,
		count->rrb, count->rrr);
}
