/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-23 15:19:03 by tmattela          #+#    #+#             */
/*   Updated: 2026-04-23 15:19:03 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *res, int fd)
{
	long	nbl;
	char	c;

	nbl = n;
	if (nbl < 0)
	{
		write(1, "-", 1);
		(*res)++;
		nbl *= -1;
	}
	if (nbl >= 10)
		ft_putnbr((int)(nbl / 10), res, fd);
	c = (nbl % 10) + 48;
	write(fd, &c, 1);
	(*res)++;
}
