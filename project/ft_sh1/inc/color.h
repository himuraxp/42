/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:16:03 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/30 19:06:00 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "libft.h"
# define COLOR      \033[
# define BLACK      30
# define RED        31
# define GREEN      32
# define YELLOW     33
# define BLUE       34
# define PINK       35
# define CYAN       36
# define GRIS       37
# define NORMAL     0
# define BOLD       1
# define UNDERLINE  4
# define TURN       5
# define HIGHLIGHT  7
# define SEP        ;
# define END        m

typedef struct		s_opt
{
    char            *init;
    const char      **c_name;
    const char      **s_name;
	char       	    **color;
    char            *style;
    char            end;
    char            sep;
}                   t_opt;

typedef struct      s_src
{
    t_opt           *init;
}                   t_src;

char    *opt_cmp(char *color, char *style, t_src *type);

t_src    *init(t_src *type);
void    init_color(t_opt *init);
void    init_style(t_opt *init);
void    init_c_name(t_opt *init);
void    ft_str_color(char *str, char *color, char *style, int end);
#endif
