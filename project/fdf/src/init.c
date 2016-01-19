/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 20:00:57 by ylarbi            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/01/14 10:29:03 by ylarbi           ###   ########.fr       */
=======
/*   Updated: 2016/01/17 17:21:49 by ylarbi           ###   ########.fr       */
>>>>>>> 63d0eed7292ad24f9f19f1fd2484ea44b68c7c10
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_data **data, char *map)
{
	ft_putstr("init start\n");
	if (!(*data = malloc(sizeof(t_data))))
		exit(-1);
	ft_putstr("init -> mlx_init\n");
	(*data)->mlx = mlx_init();
	if (!(*data)->mlx)
		exit(EXIT_FAILURE);
	(*data)->width = WIDTH;
	(*data)->height = HEIGHT;
	(*data)->win = mlx_new_window((*data)->mlx, WIDTH, HEIGHT, "FDF");
	ft_putstr("init -> get_next_map\n");
	get_next_map(*data, map);
	ft_putstr("init -> set_down\n");
	set_down(*data);
	ft_putstr("init end\n");
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

<<<<<<< HEAD
int		mouse_hook(int button, int x, int y)
=======
int     mouse_hook(int button, int x, int y)
>>>>>>> 63d0eed7292ad24f9f19f1fd2484ea44b68c7c10
{
	ft_putstr("mouse: ");
	ft_putnbr(button);
	ft_putstr(" position: ");
	ft_putnbr(x);
	ft_putchar(':');
	ft_putnbr(y);
	ft_putchar('\n');
<<<<<<< HEAD
	return (0);
=======
    return (0);
>>>>>>> 63d0eed7292ad24f9f19f1fd2484ea44b68c7c10
}
