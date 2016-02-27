/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 10:36:09 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/27 04:04:11 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_data *data)
{
	ft_draw(data);
	return (0);
}

void move(int keycode, t_data *d)
{
	if (keycode == 123)
		d->move_right -= 5;
	if (keycode == 124)
		d->move_right += 5;
	if (keycode == 125)
		d->move_down += 5;
	if (keycode == 126)
		d->move_down -= 5;
}

void 	zoom(int keycode, t_data *data)
{
	if (keycode == 69)
	{
		data->zoom_x += 1;
		data->zoom_y += 1;
	}
	else if (keycode == 78 && data->zoom_x > 1)
	{
		data->zoom_x -= 1;
		data->zoom_y -= 1;
	}
	data->start_x = (WIDTH - ((data->y + data->x + 1) * data->zoom_x)
	+ data->y * data->zoom_x + data->y * data->zoom_x) / 2 ;
	data->start_y = (HEIGHT - (data->y + data->x) * data->zoom_y) / 2;
}

void 	zoom2(int keycode, t_data *data)
{
	if (keycode == 115)
	{
		data->zoom_x += 1;
		data->zoom_y += 1;
	}
	else if (keycode == 119 && data->zoom_x > 1)
	{
		data->zoom_x -= 1;
		data->zoom_y -= 1;
	}
}

int		key_hook(int keycode, t_data *d)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		move(keycode, d);
	else if (keycode == 69 || keycode == 78)
	 	zoom(keycode, d);
	else if (keycode == 115 || keycode == 119)
	 	zoom2(keycode, d);
	else if (keycode == 116)
		d->zoom_z += 1;
	else if (keycode == 121 && d->zoom_z > 0)
		d->zoom_z -= 1;
	else if (keycode == 18)
		d->pal = 1;
	else if (keycode == 19)
		d->pal = 2;
	else if (keycode == 20)
		d->pal = 3;
	else if (keycode == 21)
		d->pal = 4;
	else if (keycode == 23)
		d->pal = 5;
	expose_hook(d);
	return (0);
}

int     mouse_hook(int button, int x, int y)
{
	ft_putstr("mouse: ");
	ft_putnbr(button);
	ft_putstr(" position: ");
	ft_putnbr(x);
	ft_putchar(':');
	ft_putnbr(y);
	ft_putchar('\n');
    return (0);
}

void 	init_data(t_data *data)
{
	data->move_down = 0;
	data->move_right = 0;
	data->zoom_z = (HEIGHT / 10) / (data->y + data->x) / 4;
	data->zoom_x = (WIDTH - 200) / (data->x + data->y);
	data->zoom_y = (HEIGHT - 200) / (data->x + data->y);
	data->pal = 1;
	data->start_x = (WIDTH - ((data->y + data->x + 1) * data->zoom_x)
	+ data->y * data->zoom_x + data->y * data->zoom_x) / 2 ;
	if (data->start_x < 0 )
		data->start_x = 0;
	data->start_y = (HEIGHT - (data->y + data->x) * data->zoom_y) / 2;
	if (data->start_y < 0 )
		data->start_y = 0;
}

int		ft_fdf(char *map)
{
	t_data	data;

	init(&data, map);
	ft_putstr("test\n");
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
		ft_str_color("Map not found", "red", "bold", 1);
		return (0);
	}
	if (ac == 2)
		ft_fdf(av[1]);
	return (0);
}
