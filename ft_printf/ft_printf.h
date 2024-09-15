/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:30:25 by dmathis           #+#    #+#             */
/*   Updated: 2024/05/31 14:43:57 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <inttypes.h>
# include <limits.h>

int	print_integer(long n);
int	print_hex(long n, char specifier);
int	print_str(char *str);
int	print_char(int c);
int	print_format(char specifier, va_list ap);
int	ft_printf(const char *format, ...)__attribute__((format(printf, 1, 2)));
int	print_point(unsigned long n, int flag);

#endif
