/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitepaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 21:49:38 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/20 21:51:43 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strndup(char *s1, int n)
{
	=char	*dup;
	char	*tmp;

	if (!(dup = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	tmp = dup;
	while (*s1 != '\0' && n--)
		*tmp++ = *s1++;
	*tmp = 0;
	return (dup);
}

int		ft_strlensplit(char *str)
{
	int i;

	i = 0;
	while (*str && *str != ' ' && *str != '\t' && *str++ != '\n')
		i++;
	return (i);
}

int		ft_strlenspace(char *str)
{
	int i;

	i = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
	{
		i++;
		str++;
	}
	return (i);
}

int		ft_countword(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
		{
			while (*str == ' ' || *str == '\t' || *str == '\n')
				str++;
			i++;
		}
		else
			str++;
	}
	return (i);
}

char	**ft_split_whitespaces(char *str)
{
	char**final;
	int	i;
	int	j;
	int	k;

	k = ft_countword(str);
	final = (char **)malloc(sizeof(char *) * (k + 1));
	final[k] = NULL;
	j = 0;
	while (j < k)
	{
		i = 0;
		i = ft_strlensplit(str + ft_strlenspace(str));
		final[j] = ft_strndup(str + ft_strlenspace(str), i);
		str += i + ft_strlenspace(str);
		j++;
	}
	return (final);
}
