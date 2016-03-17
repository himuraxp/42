/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 09:16:34 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/17 14:46:59 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	loop_carpet(t_env *e, t_carpet *c)
{
	double	xc;
	double	xc2;
	double	yc;
	double	yc2;

	c->side /= 3;
	xc = c->x + (int)c->side;
	xc2 = c->x + 2 * (int)c->side;
	yc = c->y + (int)c->side;
	yc2 = c->y + 2 * (int)c->side;
	e->x = ((int)c->x > 0) ? (int)c->x - 1 : -1;
	while (++e->x < e->x2 && e->x < c->x + c->side * 3)
	{
		e->y = ((int)c->y > 0) ? (int)c->y - 1 : -1;
		while (++e->y < e->y2 && e->y < c->y + c->side * 3)
		{
			if ((c->iter == e->iter && (e->x < c->x || e->x > c->x + c->side * 3
			|| e->y < c->y || e->y > c->y + c->side * 3)) ||
			((e->x > xc && e->x < xc2) && (e->y > yc && e->y < yc2)))
				display(e, 0, 0, 0);
			else if (c->iter == e->iter)
				display(e, e->b, e->g, e->r);
		}
	}
}

void	carpet(t_env *e, t_carpet c)
{
	if (c.iter > 0 && c.x + c.side > 0.0 && c.x <= e->x2 &&
			c.y + c.side > 0.0 && c.y <= e->y2 && c.side > 3.0)
	{
		loop_carpet(e, &c);
		c.iter--;
		carpet(e, c);
		c.y += c.side;
		carpet(e, c);
		c.y += c.side;
		carpet(e, c);
		c.x += c.side;
		c.y -= 2 * c.side;
		carpet(e, c);
		c.y += 2 * c.side;
		carpet(e, c);
		c.x += c.side;
		c.y -= 2 * c.side;
		carpet(e, c);
		c.y += c.side;
		carpet(e, c);
		c.y += c.side;
		carpet(e, c);
	}
}

void	display_carpet(t_env *e)
{
	t_carpet	c;

	c.x = e->z_r;
	c.y = e->z_i;
	c.side = e->c_r;
	c.iter = e->iter;
	carpet(e, c);
}
