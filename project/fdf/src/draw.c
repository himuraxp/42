/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 19:18:18 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/20 23:19:52 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	background(t_data *data)
{
//    t_color color;
    int x;
    int y;

    ft_putstr("background start\n");
	y = 0;
    x = 0;
    while (y <= HEIGHT)
    {
        x = 0;
        while (x <= WIDTH)
        {
            mlx_pixel_put(data->mlx, data->win, x, y, 0x000000);
            x++;
        }
        y++;
    }
    ft_putstr("background end\n");
}

void	back(t_data *data)
{
    int x;
    int y;

    y = 0;
    x = 0;
    ft_putstr("back start\n");
    while (y <= HEIGHT / 2)
    {
        x = 0;
        while (x <= WIDTH / 2)
        {
            mlx_pixel_put(data->mlx, data->win, x, y, 0x000000);
            x++;
        }
        y++;
    }
    ft_putstr("back start\n");
}

/*void	print_point(t_data *data)
{
	while (data->count != NULL)
	{
		mlx_pixel_put(data->mlx, data->win, data->map->point->x, data->map->point->y, 0xFFFFFF);
		ft_putstr("print_point while\n");
	}
}*/

void    ft_draw(t_data *data)
{
	ft_putstr("draw -> background\n");
	background(data);
	ft_putstr("draw -> back\n");
	back(data);
//	ft_putstr("draw -> print_point\n");
//	print_point(data);
}


