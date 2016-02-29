/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 19:18:18 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/29 17:00:55 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void put_pxl(t_data *d, t_line *l, t_color *c)
{
    int     pos;
    int     y;
    int     x;

    y = (((l->y0 + l->x0)) + d->start_y + d->move_down) * WIDTH * 4;
    x = (((l->x0 - l->y0)) + d->start_x + d->move_right) * 4;
    pos = y + x;
    if (pos > 0 && pos > y && pos < y + WIDTH * 4 && pos < WIDTH * HEIGHT * 4)
        {
            d->addr[pos] = c->b;
            d->addr[pos + 1] = c->g;
            d->addr[pos + 2] = c->r;
        }
}

t_color     *get_color(t_line *l, t_data *d, t_color *c, int i)
{
    c->r = 255;
    c->g = 255;
    c->b = 255;
    if (d->pal == 1)
        earth(l->z, c);
    if (d->pal == 2)
        random_c(l, d, c, i);
    if (d->pal == 3)
        random_d(l, d, c, i);
    if (d->pal == 4)
        random_e(l, d, c, i);
    if (d->pal == 5)
        random_f(l, d, c, i);
    return (c);
}

void	ft_draw(t_data *d)
{
    t_line l;
    d->zoom_y = d->zoom_x;
	d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->addr = mlx_get_data_addr(d->img, &(d->bpp), &(d->s_line), &(d->endian));
	create(d, -1, &l);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
    mlx_string_put(d->mlx, d->win, 20, 30,
			0xFFFFFF, "Zoom = +/-");
    mlx_string_put(d->mlx, d->win, 20, 60,
			0xFFFFFF, "Move = UP/DOWN/LEFT/RIGHT");
    mlx_string_put(d->mlx, d->win, 20, 90,
			0xFFFFFF, "Altitude = PageUP/PageDOWN");
    mlx_string_put(d->mlx, d->win, 20, 120,
			0xFFFFFF, "Color = 1/2/3/4/5");
	mlx_destroy_image(d->mlx, d->img);
}
