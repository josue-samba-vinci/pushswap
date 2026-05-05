/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-23 15:15:25 by tmattela          #+#    #+#             */
/*   Updated: 2026-04-23 15:15:25 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *res, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		(*res) += 6;
		return ;
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
		(*res)++;
	}
}
