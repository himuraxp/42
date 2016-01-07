/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:23:19 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/07 20:27:36 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/fdf.h"

int		ft_degrade(void)
{
	int color;

	color = 0x000000;
	while (color < 0xffffff)
	{
		color += 0x020202;
		printf("%d\n", color);
	}
	return (color);
}

void	draw(void *mlx, void *win)
{
	int color;
	int	x;
	int y;
	int x2;
	int y2;
	int x3;
	int y3;

	y = 400;
	y2 = y / 4;
	x = 400;
	x2 = x / 4;
	color = 0x090909;
	while (x2 != x / 2 && y2 != y / 2)
	{
		y3 = y - y2;
		while (y3 < y2)
		{
			x3 = x - x2;
			while (x3 < x2)
			{
				mlx_pixel_put(mlx, win, x, y, color);
				x3++;
			}

			y3++;
			if (color < 0xff00ff)
				color += 0x020815;
		}
		x2++;
		y2++;
	}
}

int		expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int		key_hook(int keycode)
{
	printf("key: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y)
{
	printf("mouse: %d position: %d:%d\n", button, x, y);
	return (0);
}

int		ft_fdf(void)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 800, 800, "42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
