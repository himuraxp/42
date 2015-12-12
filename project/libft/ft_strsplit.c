/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:05:44 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/02 16:58:51 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbr_word(char const *s, char c)
{
	int		count;
	int		nbr_word;

	nbr_word = 0;
	count = 0;
	if (s)
	{
		while (s[count])
		{
			if (s[count] != c)
			{
				nbr_word++;
				while (s[count] && s[count] != c)
					count++;
			}
			else
				count++;
		}
		return (nbr_word);
	}
	return (0);
}

static int		ft_start(char const *s, char c)
{
	int count;

	count = 0;
	if (s)
	{
		while (s[count] && s[count] == c)
			count++;
		return (count);
	}
	return (0);
}

static int		ft_len_word(char const *str, int i, char c)
{
	int size;

	size = 0;
	if (str)
	{
		while (str[i] != c && str[i])
		{
			size++;
			i++;
		}
		size++;
		return (size);
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	int		nbr_word;
	char	**tab;
	int		start;
	int		word;
	int		count;

	start = ft_start(s, c);
	word = 0;
	nbr_word = ft_nbr_word(s, c);
	if (!s || !(tab = malloc(sizeof(char*) * nbr_word + 1)))
		return (0);
	while (s[start] && word < nbr_word)
	{
		count = 0;
		if (!(tab[word] = (char*)malloc(ft_len_word(s, start, c))))
			return (NULL);
		while (s[start] != c && s[start])
			tab[word][count++] = s[start++];
		tab[word++][count] = 0;
		start++;
		while (s[start] == c && s[start])
			start++;
	}
	tab[word] = NULL;
	return (tab);
}
