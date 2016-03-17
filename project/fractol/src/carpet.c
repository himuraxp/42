/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 12:16:34 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/17 12:30:23 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	loop_carpet(t_env *e)
{
	double	xc;
	double	xc2;
	double	yc;
	double	yc2;

	e->cote /= 3;
	xc = e->car_x + (int)e->cote;
	xc2 = e->car_x + 2 * (int)e->cote;
	yc = e->car_y + (int)e->cote;
	yc2 = e->car_y + 2 * (int)e->cote;
	e->x = ((int)e->car_x > 0) ? (int)e->car_x - 1 : -1;
	while (++e->x < e->x2 && e->x < e->car_x + e->cote * 3)
	{
		e->y = ((int)e->car_y > 0) ? (int)e->car_y - 1 : -1;
		while (++e->y < e->y2 && e->y < e->car_y + e->cote * 3)
		{
			if ((e->car_iter == e->iter && (e->x < e->car_x || e->x > e->car_x + e->cote * 3
			|| e->y < e->car_y || e->y > e->car_y + e->cote * 3)) ||
			((e->x > xc && e->x < xc2) && (e->y > yc && e->y < yc2)))
				display(e, 0, 0, 0);
			else if (e->car_iter == e->iter)
				display(e, e->b, e->g, e->r);
		}
	}
}

void	carpet(t_env *e)
{
	if (e->car_iter > 0 && e->car_x + e->cote > 0.0 && e->car_x <= e->x2 &&
			e->car_y + e->cote > 0.0 && e->car_y <= e->y2 && e->cote > 3.0)
	{
		loop_carpet(e);
		e->car_iter--;
		carpet(e);
		e->car_y += e->cote;
		carpet(e);
		e->car_y += e->cote;
		carpet(e);
		e->car_x += e->cote;
		e->car_y -= 2 * e->cote;
		carpet(e);
		e->car_y += 2 * e->cote;
		carpet(e);
		e->car_x += e->cote;
		e->car_y -= 2 * e->cote;
		carpet(e);
		e->car_y += e->cote;
		carpet(e);
		e->car_y += e->cote;
		carpet(e);
	}
}

void	display_carpet(t_env *e)
{
	e->car_x = e->z_r;
	e->car_y = e->z_i;
	e->cote = e->c_r;
	e->car_iter = e->iter;
	carpet(e);
}
