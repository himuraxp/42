/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 19:18:18 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/14 22:12:56 by ylarbi           ###   ########.fr       */
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

void    draw(t_data *data)
{
	background(data);
}

/*int     expose_hook(t_data *data)
{
    draw(data->mlx, data->win);
    return (0);
}*/
