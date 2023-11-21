/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:22:49 by albozkur          #+#    #+#             */
/*   Updated: 2023/10/23 16:06:59 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(int n)
{
	return (write(1, &n, 1));
}

static int	ft_status(int n)
{
	return (n == 'c' || n == 's' || n == 'p' || n == 'd' || n == 'i'
		|| n == 'u' || n == 'x' || n == 'X' || n == '%');
}

int	ft_format(va_list args, char a)
{
	if (a == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (a == 's')
		return (ft_string(va_arg(args, char *)));
	else if (a == 'd' || a == 'i')
		return (ft_int(va_arg(args, int)));
	else if (a == 'u')
		return (ft_unsigned_int(va_arg(args, unsigned int)));
	else if (a == 'x' || a == 'X')
		return (ft_hex(va_arg(args, unsigned int), a));
	else if (a == '%')
		return (ft_putchar('%'));
	else if (a == 'p')
	{
		if (ft_string("0x") == -1)
			return (-1);
		return (ft_hex(va_arg(args, unsigned long int), a) + 2);
	}
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;
	int		value;

	i = -1;
	len = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%' && ft_status(format[i + 1]))
		{
			value = ft_format(args, format[++i]);
			if (value == -1)
				return (-1);
			len += value - 1;
		}
		else if (ft_putchar(format[i]) == -1)
			return (-1);
		len++;
	}
	va_end(args);
	return (len);
}
