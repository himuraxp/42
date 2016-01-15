/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 19:18:18 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/15 14:10:31 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	background(t_data *data)
{
    t_color color;
    int x;
    int y;

    y = 0;
    x = 0;
    while (y <= HEIGHT)
    {
        x = 0;
        while (x <= WIDTH)
        {
            mlx_pixel_put(data->mlx, data->win, x, y, ft_color(&color));
            x++;
        }
        y++;
    }
}

void	back(t_data *data)
{
    int x;
    int y;

    y = 0;
    x = 0;
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
}

void    draw(t_data *data)
{
	background(data);
	back(data);
}


