/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:16:25 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/16 14:30:09 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_env *e)
{
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->img_x = (e->x2 - e->x1) * 350;
	e->img_y = (e->y2 - e->y1) * 350;
	e->iter = 50;
}

void	init(t_env *e, char *str)
{
	e->fractol = str;
	if (ft_linecmp(e->fractol, "mandelbrot") == 0 )
		init_mandelbrot(e);
	else
		ft_error(1);
	color(e, 20);
	e->filter = 0;
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		init(&e, av[1]);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, e.img_x, e.img_y, "Fract'ol project");
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_hook(e.win, 6, (2L >> 0), &motion, &e);
		mlx_hook(e.win, 4, (2L >> 0), &mouse, &e);
		mlx_hook(e.win, 2, (2L >> 0), &key, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_error(0);
	return (0);
}
