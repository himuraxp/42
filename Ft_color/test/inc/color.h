/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 12:05:29 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/31 18:17:35 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct		s_opt
{
    char            *path;
    char            *color;
    char            *style;
    char            sep;
    char            end;
}                   t_opt;

void    ft_str_color(char *str, char *color, char *style);
char    *ft_select_color(char *color, t_opt *type);
char    *ft_select_style(char *style, t_opt *type);
void    init(char *color, char *style);
#endif
