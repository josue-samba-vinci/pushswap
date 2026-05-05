/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-23 13:37:41 by tmattela          #+#    #+#             */
/*   Updated: 2026-04-23 13:37:41 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	handle_case_letter(char c, va_list args, int *res, int fd)
{
	if (c == 'i' || c == 'd')
		ft_putnbr((int) va_arg(args, int), res, fd);
	else if (c == 's')
		ft_putstr((char *) va_arg(args, char *), res, fd);
	else if (c == 'c')
		ft_putchar((char) va_arg(args, int), res, fd);
	else if (c == 'u')
		ft_putnbr_unsigned((unsigned long) va_arg(args, unsigned long),
			res, fd);
	else if (c == 'x' || c == 'X')
		ft_putnbr_base((unsigned long)va_arg(args, unsigned int), c, res, fd);
	else if (c == 'p')
		ft_putnbr_base((unsigned long)va_arg(args, void *), c, res, fd);
	else if (c == '%')
		ft_putchar('%', res, fd);
	else
		return (0);
	return (1);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	args;
	int		i;
	int		handled_case;
	int		res;

	i = 0;
	res = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			handled_case = handle_case_letter(str[i], args, &res, fd);
			if (handled_case > 0)
				i++;
			else
				ft_putchar('%', &res, fd);
			continue ;
		}
		ft_putchar(str[i++], &res, fd);
	}
	va_end(args);
	return (res);
}
// #include <stdio.h>
// #include <limits.h>

// int main(void)
// {
//     int     nb = 42;
//     int     neg = -42;
//     char    c = 'A';
//     char    *str = "Hello, World!";
//     char    *null_str = NULL;
//     void    *ptr = &nb;
//     void    *null_ptr = NULL;
//     unsigned int u = 4294967295U;

//     printf("\n===== %%c =====\n");
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%c]\n", c));
//     printf("return value [%d]\n", printf("printf:    [%c]\n", c));
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%c]\n", 0));
//     printf("return value [%d]\n", printf("printf:    [%c]\n", 0));

//     printf("\n===== %%s =====\n");
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%s]\n", str));
//     printf("return value [%d]\n", printf("printf:    [%s]\n", str));
//     ft_printf("return value [%d]\n", ft_printf("ft_printf:
//  [%s]\n", null_str));
//     printf("return value [%d]\n", printf("printf:    [%s]\n", null_str));
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%s]\n", ""));
//     printf("return value [%d]\n", printf("printf:    [%s]\n", ""));

//     printf("\n===== %%p =====\n");
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%p]\n", ptr));
//     printf("return value [%d]\n", printf("printf:    [%p]\n", ptr));
//     ft_printf("return value [%d]\n", ft_printf("ft_printf:
// [%p]\n", null_ptr));
//     printf("return value [%d]\n", printf("printf:    [%p]\n", null_ptr));

//     printf("\n===== %%d =====\n");
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%d]\n", nb));
//     printf("return value [%d]\n", printf("printf:    [%d]\n", nb));
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%d]\n", neg));
//     printf("return value [%d]\n", printf("printf:    [%d]\n", neg));
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%d]\n", 0));
//     printf("return value [%d]\n", printf("printf:    [%d]\n", 0));
//     ft_printf("return value [%d]\n", ft_printf("ft_printf:
//  [%d]\n", INT_MAX));
//     printf("return value [%d]\n", printf("printf:    [%d]\n", INT_MAX));
//     ft_printf("return value [%d]\n", ft_printf("ft_printf:
// [%d]\n", INT_MIN));
//     printf("return value [%d]\n", printf("printf:    [%d]\n", INT_MIN));

//     printf("\n===== %%i =====\n");
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%i]\n", nb));
//     printf("return value [%d]\n", printf("printf:    [%i]\n", nb));
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%i]\n", neg));
//     printf("return value [%d]\n", printf("printf:    [%i]\n", neg));
//     ft_printf("return value [%d]\n", ft_printf("ft_printf:
// [%i]\n", INT_MIN));
//     printf("return value [%d]\n", printf("printf:    [%i]\n", INT_MIN));

//     printf("\n===== %%u =====\n");
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%u]\n", u));
//     printf("return value [%d]\n", printf("printf:    [%u]\n", u));
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%u]\n", 0));
//     printf("return value [%d]\n", printf("printf:    [%u]\n", 0));
//     ft_printf("return value [%d]\n", ft_printf("ft_printf:
// [%u]\n", (unsigned int)neg));
//     printf("return value [%d]\n", printf("printf:    [%u]\n",
// (unsigned int)neg));

//     printf("\n===== %%x =====\n");
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%x]\n", nb));
//     printf("return value [%d]\n", printf("printf:    [%x]\n", nb));
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%x]\n", 0));
//     printf("return value [%d]\n", printf("printf:    [%x]\n", 0));
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%x]\n", u));
//     printf("return value [%d]\n", printf("printf:    [%x]\n", u));

//     printf("\n===== %%X =====\n");
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%X]\n", nb));
//     printf("return value [%d]\n", printf("printf:    [%X]\n", nb));
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%X]\n", 0));
//     printf("return value [%d]\n", printf("printf:    [%X]\n", 0));
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%X]\n", u));
//     printf("return value [%d]\n", printf("printf:    [%X]\n", u));

//     printf("\n===== %%%% =====\n");
//     ft_printf("return value [%d]\n", ft_printf("ft_printf: [%%]\n"));
//     printf("return value [%d]\n", printf("printf:    [%%]\n"));

//     printf("\n===== mixed =====\n");
//     ft_printf("return value [%d]\n",
// ft_printf("ft_printf: [%d %s %c %x]\n", nb, str, c, nb));
//     printf("return value [%d]\n", printf("printf:
// [%d %s %c %x]\n", nb, str, c, nb));
//     return (0);
// }
