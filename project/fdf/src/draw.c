/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 19:18:18 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/17 17:20:18 by ylarbi           ###   ########.fr       */
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
            mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
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

void    draw(t_data *data)
{
	ft_putstr("draw -> background\n");
	background(data);
	ft_putstr("draw -> back\n");
	back(data);
}


