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

void	ft_putnbr_unsigned(unsigned int nbl, int *res, int fd)
{
	char	c;

	if (nbl >= 10)
		ft_putnbr_unsigned(nbl / 10, res, fd);
	c = (nbl % 10) + 48;
	write(fd, &c, 1);
	(*res)++;
}
