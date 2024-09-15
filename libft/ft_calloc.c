/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:37:08 by dmathis           #+#    #+#             */
/*   Updated: 2024/06/13 23:19:10 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	totalsize;

	if (nmemb == 0 || size == 0)
	{
		s = malloc(0);
		return (s);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	totalsize = (nmemb * size);
	s = (void *)malloc(totalsize);
	if (s == NULL)
		return (NULL);
	ft_memset(s, 0, totalsize);
	return (s);
}
