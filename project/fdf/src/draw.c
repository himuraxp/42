/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 19:18:18 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/27 04:20:53 by ylarbi           ###   ########.fr       */
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

int			ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

void        earth(int z, t_color *c)
{
    c->r = 0;
    c->g = 0;
    if (z == 0)
        c->b = 255;
    else if (z > -200 && z < 0)
        c->b = 255 + (z * 3.25);
    else if (z < -199)
        c->b = 55;
    else if (z < 75)
    {
        c->r = 255 - (z * 1.25);
        c->g = 255 - (z * 2.25);
        c->b = 255 - (z * 3.25);
    }
    else if (z >= 75)
    {
        c->r = 120;
        c->g = 80;
        c->b = 40;
    }
}

void color_black(t_color *c)
{
    c->r = 10;
    c->g = 10;
    c->b = 10;
    return ;
}

void color_white(t_color *c)
{
    c->r = 200;
    c->g = 200;
    c->b = 200;
    return ;
}

double     max(double nb, double max)
{
    if (nb > max)
        return (max);
    return (nb);
}

void        random_c(t_line *l, t_data *d, t_color *c, int i)
{
    int     z;
    double  range;

    z = ft_abs(l->z1) > ft_abs(l->z2) ? ft_abs(l->z1) - ft_abs(l->z2)
    : ft_abs(l->z2) - ft_abs(l->z1);
    if (l->z1 == l->z2 && l->z1 == 0)
        return (color_black(c));
    if (l->z1 == l->z2 && l->z1 > 0)
        return (color_white(c));
    range = i / (sqrt(d->zoom_x * d->zoom_x + z * z * d->zoom_z * d->zoom_z));
    if (ft_abs(l->z1) < ft_abs(l->z2))
    {
        c->r = 200 * range + 20;
        c->g = 200 * range + 20;
        c->b = 200 * range + 20;
    }
    else
    {
        c->r = 200 - max(200 * range, 200) + 20;
        c->g = 200 - max(200 * range, 200) + 20;
        c->b = 200 - max(200 * range, 200) + 20;
    }
}

void        random_d(t_line *l, t_data *d, t_color *c, int i)
{
    int     z;
    double  range;

    z = ft_abs(l->z1) > ft_abs(l->z2) ? ft_abs(l->z1) - ft_abs(l->z2)
    : ft_abs(l->z2) - ft_abs(l->z1);
    range = i / (sqrt(d->zoom_x * d->zoom_x + z * z * d->zoom_z * d->zoom_z));
    if (l->z1 == l->z2 && l->z1 == 0)
    {
        c->r = 200 * range;
        c->g = 0;
        c->b = 0;
        return ;
    }
    if (l->z1 == l->z2 && l->z1 >= 0)
    {
        c->r = 200 * range;
        c->g = 180 * range;
        c->b = 0;
        return ;
    }
    if (ft_abs(l->z1) < ft_abs(l->z2))
    {
        c->r = 150 * range + 50;
        c->g = 150 * range;
        c->b = 0;
    }
    else
    {
        c->r = 200 - 100 * range;
        if (c->r < 0)
            c->r = 0;
        c->g = 120 - 120 * range;
        if (c->g < 0)
            c->g = 0;
        c->b = 0;
    }
}

void        random_e(t_line *l, t_data *d, t_color *c, int i)
{
    int     z;
    double  range;

    z = ft_abs(l->z1) > ft_abs(l->z2) ? ft_abs(l->z1) - ft_abs(l->z2)
    : ft_abs(l->z2) - ft_abs(l->z1);
    range = i / (sqrt(d->zoom_x * d->zoom_x + z * z * d->zoom_z * d->zoom_z));
    if (l->z1 == l->z2 && l->z1 == 0)
    {
        c->r = 200 * range;
        c->g = 0;
        c->b = 0;
        return ;
    }
    if (l->z1 == l->z2 && l->z1 >= 0)
    {
        c->r = 200 * range;
        c->g = 100 * range;
        c->b = 150 * range;
        return ;
    }
    if (ft_abs(l->z1) < ft_abs(l->z2))
    {
        c->r = 150 * range + 50;
        c->g = 50 * range;
        c->b = 100 * range;
    }
    else
    {
        c->r = 200 - 100 * range;
        if (c->r < 0)
            c->r = 0;
        c->g = 60 - 60 * range;
        if (c->g < 0)
            c->g = 0;
        c->b = 120 - 120 * range;
        if (c->b < 0)
            c->b = 0;
    }
}

void        random_f(t_line *l, t_data *d, t_color *c, int i)
{
    int     z;
    double  range;

    z = ft_abs(l->z1) > ft_abs(l->z2) ? ft_abs(l->z1) - ft_abs(l->z2)
    : ft_abs(l->z2) - ft_abs(l->z1);
    range = i / (sqrt(d->zoom_x * d->zoom_x + z * z * d->zoom_z * d->zoom_z));
    if (range > 1)
        range = 1;
    if (range > 0.5)
        c->g = 200 - 150 * range;
    else
        c->g = 200 * range;
    c->r = 0;
    c->b = 0;
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

void	line(t_line *l, int dx, int dy, t_data *d)
{
    int i;
	int sx;
	int sy;
	int e2;
	int err;
    t_color c;

    i = 0;
	dx = ft_abs(l->x1 - l->x0);
	dy = ft_abs(l->y1 - l->y0);
	sx = l->x0 < l->x1 ? 1 : -1;
	sy = l->y0 < l->y1 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
        ++i;
		put_pxl(d,l, get_color(l, d, &c, i));
		if (l->x0 == l->x1 && l->y0 == l->y1)
			break;
    	e2 = err;
    	err = e2 > -dx ? err - dy : err;
    	l->x0 = e2 > -dx ? l->x0 + sx : l->x0;
    	err = e2 < dy ? err + dx : err;
    	l->y0 = e2 < dy ? l->y0 + sy : l->y0;
	}
}

void    right_trace(int i, t_data *d, t_line *l)
{
    l->x0 = d->map[i][1] * d->zoom_x;
    l->y0 = d->map[i][2] * d->zoom_y - d->map[i][0] * d->zoom_z;
    if ((i + 1) % d->x != 0)
    {
        l->z = d->map[i][0] > d->map[i + 1][0] ?
        d->map[i][0] : d->map[i + 1][0];
        l->z1 = d->map[i][0];
        l->z2 = d->map[i + 1][0];
        l->x1 = d->map[i + 1][1] * d->zoom_x;
        l->y1 = d->map[i + 1][2] * d->zoom_y - d->map[i + 1][0] * d->zoom_z;
        line(l, 0, 0, d);
    }
}
void    down_trace(int i, t_data *d, t_line *l)
{
    l->x0 = d->map[i][1] * d->zoom_x;
    l->y0 = d->map[i][2] * d->zoom_y - d->map[i][0] * d->zoom_z;
    if (i / d->x < d->y - 1)
    {
        l->z = d->map[i][0] > d->map[i + d->x][0] ?
        d->map[i][0] : d->map[i + d->x][0];
        l->z1 = d->map[i][0];
        l->z2 = d->map[i + d->x][0];
        l->x1 = d->map[i + d->x][1] * d->zoom_x;
        l->y1 = d->map[i + d->x][2] * d->zoom_y - d->map[i + d->x][0] * d->zoom_z;
        line(l, 0, 0, d);
    }
}

void    create(t_data *d, int i, t_line	*l)
{
    while (++i < d->nb_p)
    {
        right_trace(i, d, l);
        down_trace(i, d, l);
    }
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
			0xFFFFFF, "Color = !/@");
	mlx_destroy_image(d->mlx, d->img);
}
