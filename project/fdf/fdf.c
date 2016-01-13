/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:23:19 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/13 11:13:06 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/fdf.h"

int		ft_degrade(int color)
{
	if (color <= 0xFFFFFF)
	{
		color += 0x010203;
	}
	return (color);
}

void	draw(void *mlx, void *win)
{
	int	color;
	int	x;
	int y;
	int x2;
	int y2;

	y = 0;
	x = 0;
	x2 = x / 2;
	y2 = y / 2;
	color = 0x000000;
	while (x <= 400)
	{
		y = 0;
		while (y <= 400)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			y++;
		}
		color = ft_degrade(color);
		x++;
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

int		ft_fdf(char **av)
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
