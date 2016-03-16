/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:52:25 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/16 16:37:03 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_menu(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 30, 30, 0xFFFFFFFF
		, "Iteration = +/- nb:");
	mlx_string_put(e->mlx, e->win, 230, 30, 0xFFF00FFF
		, ft_itoa(e->iter));
	mlx_string_put(e->mlx, e->win, 30, 60, 0xFFFFFFFF
		, "Move = Up/Down/Left/Right");
	mlx_string_put(e->mlx, e->win, 30, 90, 0xFFFFFFFF
		, "Zoom = Scroll");
	mlx_string_put(e->mlx, e->win, 30, 120, 0xFFFFFFFF
		, "Spectre Color = 3/4");
	mlx_string_put(e->mlx, e->win, 30, 150, 0xFFFFFFFF
		, "Degrad Color = 1/2");
	mlx_string_put(e->mlx, e->win, 30, 180, 0xFFFFFFFF
		, "Active Motion Color = 0)");
	mlx_string_put(e->mlx, e->win, 30, 210, 0xFFFFFFFF
		, "Mandelbrot = num1");
	mlx_string_put(e->mlx, e->win, 30, 240, 0xFFFFFFFF
		, "Julia = num2");
	mlx_string_put(e->mlx, e->win, 30, 270, 0xFFFFFFFF
		, "Carpet = num3");
	mlx_string_put(e->mlx, e->win, 30, 300, 0xFFFFFFFF
		, "Exit = Echap");
}
