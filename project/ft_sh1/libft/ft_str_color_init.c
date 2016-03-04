/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_color_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:27:13 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/30 19:05:59 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_src    *init(t_src *type)
{
    init_c_name(type->c_name);
    init_color(type->color);
    init_style(type->s_name, type->style);
    return (type);
}

void    init_color(t_opt *color);
{
    int     i;

    i = 30;
    while (i >= 30 && i <= 37)
    {
        color[i] = itoa(0 + i);
        i++;
    }
}

void    init_style(t_opt *s_name, t_opt *style)
{
    s_name[0] = "normal";
    style = "0";
    s_name[1] = "bold";
    style = "1";
    s_name[2] = "underline";
    style = "4";
    s_name[3] = "turn";
    style = "5";
    s_name[4] = "highlight";
    style = "7";
}

void   init_c_name(t_src *init)
{
    init->init = "\033[";
    init->sep = ';';
    init->end = 'm';
    init->c_name[0] = "black";
    init->c_name[1] = "red";
    init->c_name[2] = "green";
    init->c_name[3] = "yellow";
    init->c_name[4] = "blue";
    init->c_name[5] = "pink";
    init->c_name[6] = "cyan";
    init->c_name[7] = "gris";
}
