/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_col.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 17:07:44 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/03 18:24:28 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_col(struct dirent *play, size_t max)
{
	int count;
	int tab;

	count = ft_strlen(play->d_name) + 1;
	tab = (max - count) % 4;
	while (tab > 0)
	{
		ft_putstr("\t");
		tab--;
	}
}

int		ft_len(char *str)
{
	size_t	lenmax;

	lenmax = 0;
	while (*str)
	{
		if (ft_strlen(str) > lenmax)
			lenmax = ft_strlen(str);
	}
	return (lenmax);
}
