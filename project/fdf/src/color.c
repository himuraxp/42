/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 16:46:42 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/29 16:51:06 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
