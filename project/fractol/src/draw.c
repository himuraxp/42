/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 18:33:34 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/18 11:14:41 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color(t_env *e, int key)
{
	int n;

	n = 25 / 100;
	if (key == 20)
	{
		e->b = 255 * 10 + 210 * (1 - 10);
		e->g = 40 * 10 + 21 * (1 - 10);
		e->r = 182 * 10 + 60 * (1 - 10);
	}
	if (key == 21)
	{
		e->b = 51 * n + 0 * (1 - n);
		e->g = 102 * n + 153 * (1 - n);
		e->r = 255 * n + 255 * (1 - n);
	}
}

void	display(t_env *e, int blue, int green, int red)
{
	int pos;

	pos = e->y * e->len + e->x * e->oct;
	e->img_addr[pos] = blue;
	e->img_addr[pos + 1] = green;
	e->img_addr[pos + 2] = red;
}

void	move(t_env *e, int key)
{
	double	new_img_x;
	double	new_img_y;

	if (ft_linecmp(e->fractol, "carpet") == 0)
	{
		e->z_i -= (key == 125) ? e->img_y / 20 : 0;
		e->z_i += (key == 126) ? e->img_y / 20 : 0;
		e->z_r -= (key == 124) ? e->img_x / 20 : 0;
		e->z_r += (key == 123) ? e->img_x / 20 : 0;
	}
	else
	{
		new_img_x = e->x2 - e->x1;
		new_img_y = e->y2 - e->y1;
		e->y1 += (key == 125) ? new_img_y / 20 : 0;
		e->y1 -= (key == 126) ? new_img_y / 20 : 0;
		e->x1 -= (key == 123) ? new_img_x / 20 : 0;
		e->x1 += (key == 124) ? new_img_x / 20 : 0;
		e->x2 = e->x1 + new_img_x;
		e->y2 = e->y1 + new_img_y;
	}
}

int		expose_hook(t_env *e)
{
	ft_draw(e);
	ft_draw_menu(e);
	return (0);
}

void	ft_draw(t_env *e)
{
	if (e->img)
		mlx_clear_window(e->mlx, e->win);
	if (!(e->img = mlx_new_image(e->mlx, e->img_x, e->img_y)))
		exit(0);
	if (!(e->img_addr = mlx_get_data_addr(e->img, &e->bit,
		&e->len, &e->end)))
		exit(0);
	e->oct = e->bit / 8;
	if (ft_linecmp(e->fractol, "mandelbrot") == 0)
		display_mandelbrot(e);
	if (ft_linecmp(e->fractol, "julia") == 0)
		display_julia(e);
	if (ft_linecmp(e->fractol, "carpet") == 0)
		display_carpet(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
