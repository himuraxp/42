/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:23:19 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/19 19:27:26 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(void *mlx, void *win)
{
	t_color	color;
	int	x;
	int y;

	y = 0;
	x = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			mlx_pixel_put(mlx, win, x, y, ft_color(&color));
			x++;
		}
		y++;
	}

}

int		expose_hook(t_data *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int		ft_fdf(char *map)
{
	t_data	*data;

	init(&data, map);
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_expose_hook(data->win, expose_hook, data);
	mlx_loop(data->mlx);
	return (0);
}
