/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:42:16 by mebourge          #+#    #+#             */
/*   Updated: 2022/10/31 11:33:54 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
int		ft_putstring(char *str);
int		ft_putchar(char c);
void	ft_putnubr_fd(int n, int fd, int *pnt);
int		ft_putunbr_base(unsigned long n, char *base, unsigned int len);
int		ft_conversion(char conv, va_list *var, int pnt);

#endif
