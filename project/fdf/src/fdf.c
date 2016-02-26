/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 10:36:09 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/26 15:55:39 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_data *data)
{
	ft_draw(data);
	return (0);
}

int		key_hook(int keycode, t_color *color)
{
	ft_putstr("key: ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		color->b += 0x000010;
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

int		ft_fdf(char *map)
{
	t_data	data;

	init(&data, map);
/*	mlx_key_hook(data.win, key_hook, data);
	mlx_mouse_hook(data.win, mouse_hook, data);
	mlx_expose_hook(data.win, expose_hook, data);
	mlx_loop(data.mlx);*/
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
