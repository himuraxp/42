/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:53:45 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/13 22:06:00 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1200
# define HEIGHT 800

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include "libft.h"

typedef struct	s_color
{
	int			r;
	int			v;
	int			b;
}				t_color;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct		s_node
{
	t_point			*pos;
	struct s_node	*right;
	struct s_node	*down;
}					t_node;

typedef struct		s_data
{
	t_node			*map;
	int				xmap;
	t_node			*count;
	int				i;
	void			*mlx;
	void			*win;
	int				width;
	int				height;
}					t_data;

int		ft_fdf(char *av);
int		key_hook(int keycode);
int		ft_color(t_color *color);
void	init(t_data **data, char *map);


#endif
