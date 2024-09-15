/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:08:11 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/11 15:54:53 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*bourre(char *a)
{
	a[0] = '-';
	a[1] = '2';
	a[2] = '1';
	a[3] = '4';
	a[4] = '7';
	a[5] = '4';
	a[6] = '8';
	a[7] = '3';
	a[8] = '6';
	a[9] = '4';
	a[10] = '8';
	a[11] = '\0';
	return (a);
}

int	remplissage(char *a, int isneg, int len, int temp)
{
	if (isneg == 1)
		a[0] = '-';
	a[len + isneg] = '\0';
	while (len)
	{
		len--;
		a[len + isneg] = temp % 10 + '0';
		temp = temp / 10;
	}
	return (0);
}

int	check_len(int n)
{
	int	len;
	int	temp;

	len = 1;
	temp = n;
	while (temp > 9)
	{
		len += 1;
		temp = temp / 10;
	}
	return (len);
}

int	checkifneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		isneg;
	int		len;
	int		temp;

	isneg = checkifneg(n);
	if (n == -2147483648)
	{
		a = malloc(sizeof (char) * 12);
		if (a == NULL)
			return (NULL);
		bourre(a);
		return (a);
	}
	if (isneg == 1)
		n = -n;
	len = check_len(n);
	a = malloc(sizeof(char) * (len + 1 + isneg));
	if (a == NULL)
		return (NULL);
	temp = n;
	remplissage(a, isneg, len, temp);
	return (a);
}
