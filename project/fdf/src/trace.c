/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 16:38:25 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/29 18:11:18 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line(t_line *l, int dx, int dy, t_data *d)
{
	int i;
	int sx;
	int sy;
	int e2;
	int err;
	t_color c;

	i = 0;
	dx = ft_abs(l->x1 - l->x0);
	dy = ft_abs(l->y1 - l->y0);
	sx = l->x0 < l->x1 ? 1 : -1;
	sy = l->y0 < l->y1 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		++i;
		put_pxl(d,l, get_color(l, d, &c, i));
		if (l->x0 == l->x1 && l->y0 == l->y1)
			break;
    	e2 = err;
    	err = e2 > -dx ? err - dy : err;
    	l->x0 = e2 > -dx ? l->x0 + sx : l->x0;
    	err = e2 < dy ? err + dx : err;
    	l->y0 = e2 < dy ? l->y0 + sy : l->y0;
	}
}

void	right_trace(int i, t_data *d, t_line *l)
{
	l->x0 = d->map[i][1] * d->zoom_x;
	l->y0 = d->map[i][2] * d->zoom_y - d->map[i][0] * d->zoom_z;
	if ((i + 1) % d->x != 0)
	{
		l->z = d->map[i][0] > d->map[i + 1][0] ?
		d->map[i][0] : d->map[i + 1][0];
		l->z1 = d->map[i][0];
		l->z2 = d->map[i + 1][0];
		l->x1 = d->map[i + 1][1] * d->zoom_x;
		l->y1 = d->map[i + 1][2] * d->zoom_y - d->map[i + 1][0] * d->zoom_z;
		line(l, 0, 0, d);
	}
}

void	down_trace(int i, t_data *d, t_line *l)
{
	l->x0 = d->map[i][1] * d->zoom_x;
	l->y0 = d->map[i][2] * d->zoom_y - d->map[i][0] * d->zoom_z;
	if (i / d->x < d->y - 1)
	{
		l->z = d->map[i][0] > d->map[i + d->x][0] ?
		d->map[i][0] : d->map[i + d->x][0];
		l->z1 = d->map[i][0];
		l->z2 = d->map[i + d->x][0];
		l->x1 = d->map[i + d->x][1] * d->zoom_x;
		l->y1 = d->map[i + d->x][2] * d->zoom_y - d->map[i + d->x][0] * d->zoom_z;
		line(l, 0, 0, d);
	}
}

void	create(t_data *d, int i, t_line	*l)
{
	while (++i < d->nb_p)
	{
		right_trace(i, d, l);
		down_trace(i, d, l);
	}
}
