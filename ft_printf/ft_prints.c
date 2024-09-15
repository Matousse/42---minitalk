/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:15:04 by dmathis           #+#    #+#             */
/*   Updated: 2024/05/30 16:56:14 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_point(unsigned long n, int flag)
{
	int	shift;
	int	count;

	count = 0;
	if (n == '\0')
		return (write(1, "(nil)", 5));
	if (flag == 0)
	{
		flag = 1;
		count += print_str("0x");
	}
	shift = 87;
	if (n / 16)
	{
		count += print_point(n / 16, flag);
	}
	if ((n % 16) < 10)
		count += print_char((n % 16) + '0');
	else
		count += print_char((n % 16) + shift);
	return (count);
}

int	print_integer(long n)
{
	int		count;
	char	conv;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count += write(1, "-", 1);
	}
	if (n >= 10)
	{
		count += print_integer(n / 10);
	}
	conv = (n % 10) + '0';
	count += write(1, &conv, 1);
	return (count);
}

int	print_hex(long n, char specifier)
{
	int		count;
	char	*symboles_min;
	char	*symboles_maj;

	count = 0;
	symboles_min = "0123456789abcdef";
	symboles_maj = "0123456789ABCDEF";
	if (n < 0)
		return ((print_hex(-(unsigned long)n, specifier)) + 1);
	else if (n < 16)
	{
		if (specifier == 'x')
			return (print_char(symboles_min[n]));
		else
			return (print_char(symboles_maj[n]));
	}
	else
	{
		count = print_hex(n / 16, specifier);
		return (count + print_hex(n % 16, specifier));
	}
}

int	print_str(char *str)
{
	int	len;
	int	count;

	count = 0;
	if (str == NULL)
	{
		count = write(1, "(null)", 6);
		return (count);
	}
	len = 0;
	while (str[len])
	{
		count += write(1, &str[len], 1);
		len++;
	}
	return (count);
}

int	print_char(int c)
{
	return (write(1, &c, 1));
}
