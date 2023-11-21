/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:22:30 by albozkur          #+#    #+#             */
/*   Updated: 2023/10/23 16:08:24 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_string(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (ft_string("(null)") == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_int(int n)
{
	int		step;
	int		value;

	step = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n == -2147483648)
		return (ft_string("-2147483648"));
	if (n < 0)
	{
		step++;
		if (ft_putchar('-') == -1)
			return (-1);
		n *= -1;
	}
	if (n > 9)
	{
		value = ft_int(n / 10);
		if (value == -1)
			return (-1);
		step += value;
	}
	if (ft_putchar("0123456789"[n % 10]) == -1)
		return (-1);
	return (step + 1);
}

int	ft_unsigned_int(unsigned int num)
{
	int	step;
	int	value;

	step = 0;
	if (num == 0)
		return (ft_putchar('0'));
	if (num > 9)
	{
		value = ft_int(num / 10);
		if (value == -1)
			return (-1);
		step += value;
	}
	if (ft_putchar("0123456789"[num % 10]) == -1)
		return (-1);
	return (step + 1);
}

int	ft_hex(unsigned long int num, char status)
{
	int	value;
	int	len;

	len = 0;
	if (num >= 16)
	{
		value = ft_hex(num / 16, status);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (status == 'x' || status == 'p')
	{
		if (ft_putchar("0123456789abcdef"[num % 16]) == -1)
			return (-1);
	}
	else if (status == 'X')
	{
		if (ft_putchar("0123456789ABCDEF"[num % 16]) == -1)
			return (-1);
	}
	return (len + 1);
}
