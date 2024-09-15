/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:40:51 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/11 16:20:37 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_maison(char **tab, int nbw)
{
	int	k;

	k = 0;
	while (k < nbw)
	{
		free(tab[k]);
		k++;
	}
	free(tab);
}

char	*my_strcpy(char *dest, const char *src, int n)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = dest;
	while (i < n)
	{
		*ptr++ = *src++;
		i++;
	}
	*ptr = '\0';
	return (dest);
}

int	countwords(char const *str, char c)
{
	int	nbw;
	int	i;

	i = 0;
	nbw = 0;
	while ((str[i] == c) && str[i])
		i++;
	while (str[i])
	{
		if (str[i] != c)
		{
			if ((str[i + 1] == c || str[i + 1] == '\0'))
				nbw += 1;
		}
		i++;
	}
	return (nbw);
}

char	**createchains(char const *str, char c, char **tab, int nbw)
{
	int	i;
	int	currentw;
	int	j;

	i = 0;
	currentw = 0;
	while (currentw < nbw)
	{
		while ((str[i] == c) && str[i])
			i++;
		j = i;
		while ((str[i] != c) && str[i])
			i++;
		tab[currentw] = malloc(sizeof(char) * (i - j + 1));
		if (tab[currentw] == NULL)
		{
			free_maison(tab, currentw);
			return (NULL);
		}
		tab[currentw] = my_strcpy(tab[currentw], &str[j], i - j);
		currentw++;
	}
	tab[currentw] = 0;
	return (tab);
}

char	**ft_split(char const *str, char c)
{
	int		nbw;
	char	**tab;

	nbw = countwords(str, c);
	tab = malloc((sizeof(char *) * (nbw + 1)));
	if (tab == NULL)
		return (NULL);
	tab = createchains(str, c, tab, nbw);
	if (tab == NULL)
		return (NULL);
	return (tab);
}
