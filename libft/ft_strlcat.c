/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:51:47 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/11 15:55:00 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_alloc_size)
{
	size_t	isrc;
	size_t	dlen;
	size_t	slen;

	isrc = 0;
	dlen = 0;
	slen = 0;
	if (dest_alloc_size == 0 && (!dest || !src))
		return (0);
	while (dest[dlen])
		dlen++;
	while (src[slen])
		slen++;
	if (dlen >= dest_alloc_size)
		return (slen + dest_alloc_size);
	while (src[isrc] && (isrc < (dest_alloc_size - dlen - 1)))
	{
		dest[dlen + isrc] = src[isrc];
		isrc++;
	}
	dest[dlen + isrc] = '\0';
	return (dlen + slen);
}
