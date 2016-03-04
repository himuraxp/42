/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:25:01 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/30 19:06:02 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void ft_str_color(char *str, char *color, char *style, int end)
{
    t_src   *type;
    char    *tmp;

    *type = *init(type);
    if (!(tmp = opt_cmp(color, style, type)))
        ft_putstr(str);
    else
    {
        ft_putstr(tmp);
        ft_putstr(str);
    }
    if (end == 0)
        ft_putstr("\033[0m");
}
