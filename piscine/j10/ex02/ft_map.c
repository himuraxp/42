/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 15:50:39 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/21 16:12:59 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *tab_malloc;

	i = 0;
	tab_malloc = (int*)malloc(sizeof(*tab_malloc) * length + 1);
	while (i < length)
	{
		tab_malloc[i] = tab[i];
		i++;
	}
	return (tab_malloc);
}
