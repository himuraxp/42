/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:57:33 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/16 16:27:54 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia(t_env *e)
{
	e->c_r = e->v_r;
	e->c_i = e->v_i;
	e->z_r = (e->x * (e->x2 - e->x1) / e->img_x) + e->x1;
	e->z_i = (e->y * (e->y2 - e->y1) / e->img_y) + e->y1;
	return (0);
}

void	display_julia(t_env *e)
{
	int		i;
	double	tmp;

	e->x = -1;
	while (++e->x < e->img_x)
	{
		e->y = -1;
		while (++e->y < e->img_y)
		{
			i = julia(e);
			while (i++ < e->iter && e->z_r * e->z_r + e->z_i * e->z_i < 4)
			{
				tmp = e->z_r;
				e->z_r = (e->z_r * e->z_r) - (e->z_i * e->z_i) + e->c_r;
				e->z_i = 2 * e->z_i * tmp + e->c_i;
			}
			if (i == e->iter)
				display(e, 0, 0, 0);
			else
				display(e, i * 255 / e->iter - e->b - 255, i * 255 /
					e->iter - e->g - 255, i * 255 / e->iter - e->r - 255);
		}
	}
}
