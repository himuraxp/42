/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 16:46:42 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/03 14:33:00 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	earth(int z, t_color *c)
{
	c->r = 0;
	c->g = 0;
	if (z == 0)
		c->b = 255;
	else if (z > -200 && z < 0)
		c->b = 255 + (z * 3.25);
	else if (z < -199)
		c->b = 55;
	else if (z < 75)
	{
		c->r = 255 - (z * 1.25);
		c->g = 255 - (z * 2.25);
		c->b = 255 - (z * 3.25);
	}
	else if (z >= 75)
		color_rgb(c, 120, 80, 40);
}

void	random_c(t_line *l, t_data *d, t_color *c, int i)
{
	int		z;
	double	range;

	z = ft_abs(l->z1) > ft_abs(l->z2) ? ft_abs(l->z1) - ft_abs(l->z2)
	: ft_abs(l->z2) - ft_abs(l->z1);
	if (l->z1 == l->z2 && l->z1 == 0)
		return (color_black(c));
	if (l->z1 == l->z2 && l->z1 > 0)
		return (color_white(c));
	range = i / (sqrt(d->zoom_x * d->zoom_x + z * z * d->zoom_z * d->zoom_z));
	if (ft_abs(l->z1) < ft_abs(l->z2))
	{
		c->r = 200 * range + 20;
		c->g = 200 * range + 20;
		c->b = 200 * range + 20;
	}
	else
	{
		c->r = 200 - max(200 * range, 200) + 20;
		c->g = 200 - max(200 * range, 200) + 20;
		c->b = 200 - max(200 * range, 200) + 20;
	}
}

void	random_d(t_line *l, t_data *d, t_color *c, int i)
{
	int		z;
	double	range;

	z = ft_abs(l->z1) > ft_abs(l->z2) ? ft_abs(l->z1) - ft_abs(l->z2)
	: ft_abs(l->z2) - ft_abs(l->z1);
	range = i / (sqrt(d->zoom_x * d->zoom_x + z * z * d->zoom_z * d->zoom_z));
	if (l->z1 == l->z2 && l->z1 == 0)
		return (color_rgb(c, 200 * range, 0, 0));
	if (l->z1 == l->z2 && l->z1 >= 0)
		return (color_rgb(c, 200 * range, 180 * range, 0));
	if (ft_abs(l->z1) < ft_abs(l->z2))
		color_rgb(c, 150 * range + 50, 150 * range, 0);
	else
	{
		color_rgb(c, 200 - 100 * range, 120 - 120 * range, 0);
		if (c->r < 0)
			c->r = 0;
		if (c->g < 0)
			c->g = 0;
	}
}

void	random_e(t_line *l, t_data *d, t_color *c, int i)
{
	int		z;
	double	range;

	z = ft_abs(l->z1) > ft_abs(l->z2) ? ft_abs(l->z1) - ft_abs(l->z2)
	: ft_abs(l->z2) - ft_abs(l->z1);
	range = i / (sqrt(d->zoom_x * d->zoom_x + z * z * d->zoom_z * d->zoom_z));
	if (l->z1 == l->z2 && l->z1 == 0)
		return (color_rgb(c, 200 * range, 0, 0));
	if (l->z1 == l->z2 && l->z1 >= 0)
		return (color_rgb(c, 200 * range, 100 * range, 150 * range));
	if (ft_abs(l->z1) < ft_abs(l->z2))
	{
		color_rgb(c, 150 * range + 50, 50 * range, 100 * range);
	}
	else
	{
		color_rgb(c, 200 - 100 * range, 60 - 60 * range, 120 - 120 * range);
		if (c->r < 0)
			c->r = 0;
		if (c->g < 0)
			c->g = 0;
		if (c->b < 0)
			c->b = 0;
	}
}

void	random_f(t_line *l, t_data *d, t_color *c, int i)
{
	int		z;
	double	range;

	z = ft_abs(l->z1) > ft_abs(l->z2) ? ft_abs(l->z1) - ft_abs(l->z2)
	: ft_abs(l->z2) - ft_abs(l->z1);
	range = i / (sqrt(d->zoom_x * d->zoom_x + z * z * d->zoom_z * d->zoom_z));
	if (range > 1)
		range = 1;
	if (range > 0.5)
		c->g = 200 - 150 * range;
	else
		c->g = 200 * range;
	c->r = 0;
	c->b = 0;
}
