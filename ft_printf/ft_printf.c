/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:02:35 by dmathis           #+#    #+#             */
/*   Updated: 2024/05/31 14:47:56 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'i' || specifier == 'd')
		count += print_integer((long)va_arg(ap, int));
	else if (specifier == 'u')
		count += print_integer((unsigned long)va_arg(ap, unsigned int));
	else if (specifier == 'p')
		count += print_point((unsigned long)va_arg(ap, void *), 0);
	else if (specifier == 'x' || specifier == 'X')
		count += print_hex(va_arg(ap, unsigned int), specifier);
	else if (specifier == '%')
		count += write(1, "%", 1);
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		ret;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			ret = print_format(*(++format), ap);
			if (ret == -1)
				return (-1);
			count += ret;
		}
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
