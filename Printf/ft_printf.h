/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:23:47 by albozkur          #+#    #+#             */
/*   Updated: 2023/10/23 15:53:27 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(int n);
int	ft_string(char *str);
int	ft_int(int n);
int	ft_point(unsigned long int num, int status);
int	ft_unsigned_int(unsigned int num);
int	ft_hex(unsigned long int num, char status);
int	ft_printf(const char *format, ...);

#endif
