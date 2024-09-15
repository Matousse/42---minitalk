/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:35:36 by dmathis           #+#    #+#             */
/*   Updated: 2024/06/13 23:21:34 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		len;

	len = 0;
	if (*src == '\0')
	{
		*dest = '\0';
		return (0);
	}
	while (src[len])
		len++;
	if (len < 1)
		return (len);
	i = 0;
	if (n == 0)
		return (len);
	while ((i < (n - 1)) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
