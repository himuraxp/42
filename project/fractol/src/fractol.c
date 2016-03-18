/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:16:25 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/18 11:14:20 by ylarbi           ###   ########.fr       */
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
	e->bloc = 0;
	e->iter = 20;
}

void	init_julia(t_env *e)
{
	e->x1 = -1.5;
	e->x2 = 1.2;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->v_r = 0.285;
	e->v_i = 0.01;
	e->img_x = (e->x2 - e->x1) * 350;
	e->img_y = (e->y2 - e->y1) * 350;
	e->bloc = 0;
	e->iter = 20;
}

void	init_carpet(t_env *e)
{
	e->x1 = 0;
	e->x2 = 945;
	e->y1 = 0;
	e->y2 = 840;
	e->img_x = e->x2 - e->x1;
	e->img_y = e->y2 - e->y1;
	e->c_r = e->img_x / 1.5;
	e->z_r = (e->img_x - e->c_r) / 2;
	e->z_i = (e->img_y - e->c_r) / 2;
	e->bloc = 0;
	e->iter = 20;
}

void	init(t_env *e, char *str)
{
	e->fractol = str;
	color(e, 20);
	if (ft_linecmp(e->fractol, "mandelbrot") == 0)
	{
		init_mandelbrot(e);
		ft_putstr("\033[1;30m-->\033[35;1m ");
		ft_putstr(e->fractol);
	}
	else if (ft_linecmp(e->fractol, "julia") == 0)
	{
		init_julia(e);
		ft_putstr("\033[1;30m-->\033[35;1m ");
		ft_putstr(e->fractol);
	}
	else if (ft_linecmp(e->fractol, "carpet") == 0)
	{
		init_carpet(e);
		ft_putstr("\033[1;30m-->\033[35;1m ");
		ft_putstr(e->fractol);
	}
	else
		ft_error(1);
	ft_putstr("\033[m\n");
	e->filter = 0;
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		init(&e, arg_convert(av[1]));
		if ((e.mlx = mlx_init()) == NULL)
			exit(0);
		if (!(e.win = mlx_new_window(e.mlx, e.img_x, e.img_y, "Fract'ol")))
			exit(0);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_hook(e.win, 6, (1L >> 0), &motion, &e);
		mlx_hook(e.win, 4, (1L >> 0), &mouse, &e);
		mlx_hook(e.win, 2, (1L >> 0), &key, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_error(1);
	return (0);
}
