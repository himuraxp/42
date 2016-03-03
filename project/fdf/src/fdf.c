/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 10:36:09 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/03 15:02:51 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_data *data)
{
	ft_draw(data);
	return (0);
}

void	init_data(t_data *data)
{
	data->move_down = 0;
	data->move_right = 0;
	data->zoom_z = (HEIGHT / 10) / (data->y + data->x) / 4;
	data->zoom_x = (WIDTH - 200) / (data->x + data->y);
	data->zoom_y = (HEIGHT - 200) / (data->x + data->y);
	data->pal = 1;
	data->start_x = (WIDTH - ((data->y + data->x + 1) * data->zoom_x)
	+ data->y * data->zoom_x + data->y * data->zoom_x) / 2;
	if (data->start_x < 0)
		data->start_x = 0;
	data->start_y = (HEIGHT - (data->y + data->x) * data->zoom_y) / 2;
	if (data->start_y < 0)
		data->start_y = 0;
}

int		ft_fdf(char *map)
{
	t_data	data;

	init(&data, map);
	init_data(&data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 2, 1, key_hook, &data);
	mlx_expose_hook(data.win, expose_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putendl("Map not found");
		return (0);
	}
	if (ac == 2)
		ft_fdf(av[1]);
	return (0);
}
