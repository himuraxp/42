/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:16:25 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/15 17:58:10 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_mandel(t_env *e)
{
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->img_x = (e->x2 - e->x1) * 300;
	e->img_y = (e->y2 - e->y1) * 300;
	e->im = 50;
}

void	init(t_env *e, char *str)
{
	e->fractol = str;
	if (ft_linecmp(e->fractol, "mandelbrot") == 0)
		init_mandel(e);
	else
		ft_error(1);
	e->b = 255;
	e->g = 255;
	e->r = 255;
	e->block = 0;
}

int		main(int ac, char *ac)
{
	t_env	e;

	if (ac == 2)
	{
		init(&e, av[1]);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, e.img_x, e.img_y, "Fract'ol project");
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_hook(e.win, 6, (1L >> 0), &motion_notify, &e);
		mlx_hook(e.win, 4, (1L >> 0), &mouse_press, &e);
		mlx_hook(e.win, 2, (1L >> 0), &key_press, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_error(0);
	return (0);
}
