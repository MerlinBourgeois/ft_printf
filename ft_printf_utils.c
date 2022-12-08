/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:14:04 by mebourge          #+#    #+#             */
/*   Updated: 2022/10/31 11:38:00 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
			i++;
	}
	return (i);
}

int	ft_putstring(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = ft_strlen(str);
	write(1, str, i);
	return (i);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

void	ft_putnubr_fd(int n, int fd, int *pnt)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnubr_fd(147483648, fd, pnt);
		*pnt = 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		(*pnt)++;
	}
	if (n < 10)
	{
		ft_putchar((n + 48));
		(*pnt)++;
		return ;
	}
	ft_putnubr_fd(n / 10, fd, pnt);
	ft_putchar((n % 10) + '0');
	(*pnt)++;
}

int	ft_putunbr_base(unsigned long n, char *base, unsigned int len)
{
	int	ret;

	if (n < len)
	{
		write(1, &base[n], 1);
		return (1);
	}
	ret = ft_putunbr_base(n / len, base, len);
	return (ret + ft_putunbr_base(n % len, base, len));
}
