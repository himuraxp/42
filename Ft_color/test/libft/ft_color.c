/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 11:00:24 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/31 18:20:18 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "color.h"

char    *ft_select_style(char *style, t_opt *type)
{
    if (ft_strcmp(style, "norm") == 0)
        type->style = "0";
    if (ft_strcmp(style, "bold") == 0)
        type->style = "1";
    if (ft_strcmp(style, "uline") == 0)
        type->style = "4";
    if (ft_strcmp(style, "turn") == 0)
        type->style = "5";
    if (ft_strcmp(style, "hlight") == 0)
        type->style = "7";
    return (type->style);
}

char    *ft_select_color(char *color, t_opt *type)
{
    type->color[0] = '3';
    if (ft_strcmp(color, "black") == 0)
        type->color[1] = '0';
    if (ft_strcmp(color, "red") == 0)
        type->color[1] = '1';
    if (ft_strcmp(color, "green") == 0)
        type->color[1] = '2';
    if (ft_strcmp(color, "yellow") == 0)
        type->color[1] = '3';
    if (ft_strcmp(color, "blue") == 0)
        type->color[1] = '4';
    if (ft_strcmp(color, "pink") == 0)
        type->color[1] = '5';
    if (ft_strcmp(color, "cyan") == 0)
        type->color[1] = '6';
    if (ft_strcmp(color, "gris") == 0)
        type->color[1] = '7';
    return (type->color);
}

void    init(char *color, char *style)
{
    t_opt   type;

    type.path = ft_strnew(5);
    type.color = ft_strnew(2);
    type.style = ft_strnew(1);
    ft_strcpy(type.path, "\033[");
    ft_putstr(type.path);
    if (!style)
    {
        type.color = ft_select_color(color, &type);
        ft_putstr(type.color);
    }
    else if (!color)
    {
        type.style = ft_select_style(style, &type);
        ft_putstr(type.style);
    }
    else
    {
        type.color = ft_select_color(color, &type);
        ft_putstr(type.color);
        type.sep = ';';
        ft_putchar(type.sep);
        type.style = ft_select_style(style, &type);
        ft_putstr(type.style);
    }
    type.end = 'm';
    ft_putchar(type.end);
}

void    ft_str_color(char *str, char *color, char *style)
{
    init(color, style);
    ft_putstr(str);
    ft_putstr("\033[0m");
}
