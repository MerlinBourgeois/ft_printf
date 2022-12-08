/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:59:27 by mebourge          #+#    #+#             */
/*   Updated: 2022/10/31 11:28:54 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(char conv, va_list *var, int pnt)
{
	if (conv == 'u')
		return (ft_putunbr_base(va_arg(*var, unsigned int), "0123456789", 10));
	if (conv == 'x')
		return (ft_putunbr_base(va_arg(*var, unsigned int),
				"0123456789abcdef", 16));
	if (conv == 'X')
		return (ft_putunbr_base(va_arg(*var, unsigned int),
				"0123456789ABCDEF", 16));
	if (conv == 'i' || conv == 'd')
	{
		ft_putnubr_fd(va_arg(*var, int), 1, &pnt);
		return (pnt);
	}
	if (conv == 'c')
		return (ft_putchar(va_arg(*var, int)));
	if (conv == 's')
		return (ft_putstring(va_arg(*var, char *)));
	if (conv == '%')
		return (ft_putchar('%'));
	if (conv == 'p')
		return (ft_putstring("0x")
			+ ft_putunbr_base(va_arg(*var, unsigned long),
				"0123456789abcdef", 16));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	var;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(var, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			count++;
		}
		else
		{
			count += ft_conversion(str[i + 1], &var, 0);
			i++;
		}
		i++;
	}
	va_end(var);
	return (count);
}

/*

#include <stdio.h>
int main(void)
{
	char *s = "hello je suis bo";
	printf("%d\n", ft_printf("%s\n", s));	
	printf("%d\n", printf("%s\n", s));
}

*/
