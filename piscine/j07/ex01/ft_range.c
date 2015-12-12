/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 16:02:58 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/16 22:08:07 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int i;

	i = 0;
	tab = (int*)malloc(sizeof(*tab) * (max - min));
	if (tab == 0 || min >= max)
		return (0);
	while (i < max - min)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
