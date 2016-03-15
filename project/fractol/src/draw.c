/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 18:33:34 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/15 21:11:34 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display(t_env *e, int blue, int green, int red)
{
	e->img_addr[e->y * e->len + e->x * e->bit / 8] = blue;
	e->img_addr[e->y * e->len + e->x * e->bit / 8 + 1] = green;
	e->img_addr[e->y * e->len + e->x * e->bit / 8 + 2] = red;
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
	return (0);
}

void	ft_draw(t_env *e)
{
	if (e->img)
		mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, e->img_x, e->img_y);
	e->img_addr = mlx_get_data_addr(e->img, &e->bit,
		&e->len, &e->end);
	if (ft_linecmp(e->fractol, "mandelbrot") == 0)
		display_mandelbrot(e);
//	if (ft_linecmp(e->fractol, "julia") == 0)
//		display_julia(e);
//	if (ft_linecmp(e->fractol, "carpet") == 0)
//		display_carpet(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
