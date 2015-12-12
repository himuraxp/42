/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 21:25:39 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/17 09:15:12 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate(int **range, int min, int max)
{
	int *tab;
	int i;

	i = 0;
	tab = (int*)malloc(sizeof(*tab) * (max - min));
	if (range == 0 || min >= max)
		return (range);
	while (i < max - min)
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	return (i + 1);
}
