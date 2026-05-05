/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-23 13:37:57 by tmattela          #+#    #+#             */
/*   Updated: 2026-04-23 13:37:57 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(int fd, const char *str, ...);
void	ft_putstr(char *s, int *res, int fd);
void	ft_putnbr(int n, int *res, int fd);
void	ft_putchar(char c, int *res, int fd);
void	ft_putnbr_unsigned(unsigned int nbl, int *res, int fd);
void	ft_putnbr_base(unsigned long nbr, char c, int *res, int fd);

#endif
