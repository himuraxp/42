/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 19:58:49 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/17 17:03:15 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*new_point(float x, float y, float z)
{
	t_point	*new;
	ft_putstr("new_point start\n");
	if (!(new = malloc(sizeof(t_point))))
		return (0);
	new->x = (x - y) * ZOOM;
	new->y = (x + y) * ZOOM;
	new->y -= (z * POS) / 4;
	new->x += (800 / 2);
	new->y += (600 / 2);
	new->z = z;
	ft_putstr("new_point end\n");
	return(new);
}
