/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-25 13:56:52 by tmattela          #+#    #+#             */
/*   Updated: 2026-04-25 13:56:52 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_custom(unsigned long nbl, char *base, int *res, int fd)
{
	char			c;
	unsigned long	base_len;

	base_len = 16;
	if (nbl >= base_len)
		ft_putnbr_custom(nbl / base_len, base, res, fd);
	c = base[nbl % base_len];
	write(fd, &c, 1);
	(*res)++;
}

void	ft_putnbr_base(unsigned long nbr, char c, int *res, int fd)
{
	char	*base;

	if (nbr == 0 && c != 'p')
	{
		write(1, "0", 1);
		(*res)++;
		return ;
	}
	base = "0123456789ABCDEF";
	if (c == 'p' || c == 'x')
		base = "0123456789abcdef";
	if (c == 'p')
	{
		if (!nbr)
		{
			ft_putstr("(nil)", res, fd);
			return ;
		}
		ft_putchar('0', res, fd);
		ft_putchar('x', res, fd);
	}
	ft_putnbr_custom((unsigned long)nbr, base, res, fd);
}
