/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 18:26:17 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/17 14:45:11 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_next(t_env *e, int keycode)
{
	if (keycode == 83)
		e->fractol = "mandelbrot";
	else if (keycode == 84)
		e->fractol = "julia";
	else if (keycode == 85)
		e->fractol = "carpet";
	init(e, e->fractol);
}

int		key(int key, t_env *e)
{
	if (key == 53)
		exit(0);
	e->iter += (key == 69) ? 20 : 0;
	e->iter -= (key == 78 && e->iter > 20) ? 20 : 0;
	if (key == 82)
		e->filter = (e->filter == 0) ? 1 : 0;
	if (key == 18)
	{
		e->b -= (e->b > 4) ? 5 : 0;
		e->g -= (e->g > 4) ? 5 : 0;
		e->r -= (e->r > 4) ? 5 : 0;
	}
	if (key == 19)
	{
		e->b += (e->b < 254) ? 5 : 0;
		e->g += (e->g < 254) ? 5 : 0;
		e->r += (e->r < 254) ? 5 : 0;
	}
	color(e, key);
	move(e, key);
	if (key >= 83 && key <= 85)
		fractol_next(e, key);
	ft_draw(e);
	ft_draw_menu(e);
	return (key);
}

void	zoom(t_env *e, int x, int y, int key)
{
	double	zoom_x;
	double	zoom_y;

	zoom_x = (x * (e->x2 - e->x1) / e->img_x) + e->x1;
	zoom_y = (y * (e->y2 - e->y1) / e->img_y) + e->y1;
	if (key == 5 || key == 6)
	{
		e->x2 = zoom_x + (e->x2 - zoom_x) / 1.1;
		e->y2 = zoom_y + (e->y2 - zoom_y) / 1.1;
		e->x1 = zoom_x + (e->x1 - zoom_x) / 1.1;
		e->y1 = zoom_y + (e->y1 - zoom_y) / 1.1;
	}
	if (key == 4 || key == 7)
	{
		e->x2 = zoom_x + (e->x2 - zoom_x) * 1.1;
		e->y2 = zoom_y + (e->y2 - zoom_y) * 1.1;
		e->x1 = zoom_x + (e->x1 - zoom_x) * 1.1;
		e->y1 = zoom_y + (e->y1 - zoom_y) * 1.1;
	}
}

int		motion(int x, int y, t_env *e)
{
	if ((ft_linecmp(e->fractol, "julia") == 0))
	{
		e->v_r = (double)(x - 110) / 1000;
		e->v_i = (double)(y - 110) / 1000;
		if (e->filter == 1)
		{
			if (x > 0 && x < e->img_x)
				e->b = x * 255 / e->img_x;
			if (y > 0 && y < e->img_y)
				e->g = y * 255 / e->img_y;
		}
		ft_draw(e);
		ft_draw_menu(e);
	}
	else if (e->filter == 1)
	{
		if (x > 0 && x < e->img_x)
			e->b = x * 255 / e->img_x;
		if (y > 0 && y < e->img_y)
			e->g = y * 255 / e->img_y;
		ft_draw(e);
		ft_draw_menu(e);
	}
	return (0);
}

int		mouse(int key, int x, int y, t_env *e)
{
	if (ft_linecmp(e->fractol, "carpet") == 0)
	{
		if (key == 5)
		{
			e->c_r *= 1.1;
			e->z_r += (e->z_r - x) * 0.1;
			e->z_i += (e->z_i - y) * 0.1;
		}
		if (key == 4)
		{
			e->c_r *= 0.9;
			e->z_r -= (e->z_r - x) * 0.1;
			e->z_i -= (e->z_i - y) * 0.1;
		}
	}
	else
		zoom(e, x, y, key);
	ft_draw(e);
	ft_draw_menu(e);
	return (0);
}
