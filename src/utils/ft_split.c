/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-29 09:06:56 by tmattela          #+#    #+#             */
/*   Updated: 2026-04-29 09:06:56 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] != c && i == 0) || (str[i] != c && str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	write_split(char **tab, char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != c && str[i + j])
				j++;
			*tab = malloc(sizeof(char) * (j + 1));
			if (!*tab)
				return (0);
			j = 0;
			while (str[i] != c && str[i])
				(*tab)[j++] = str[i++];
			(*tab)[j] = '\0';
			tab++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		success;
	char	**start;

	if (!s)
		return (NULL);
	words = count_words((char *)s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab[words] = NULL;
	success = write_split(tab, (char *)s, c);
	if (success == 0)
	{
		start = tab;
		while (*tab)
		{
			free(*tab);
			tab++;
		}
		free(start);
		return (NULL);
	}
	return (tab);
}
