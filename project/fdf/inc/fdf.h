/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:53:45 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/15 19:00:25 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH	1200
# define HEIGHT	800
# define ZOOM	20
# define POS	10

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
	t_point			*point;
	struct s_node	*right;
	struct s_node	*down;
}					t_node;

typedef struct		s_data
{
	t_node			*map;
	int				xmap;
	t_node			*count;
	int				o;
	void			*mlx;
	void			*win;
	int				width;
	int				height;
}					t_data;

int		ft_fdf(char *av);
int		ft_color(t_color *color);
int		key_hook(int keycode, t_color *color);
int		mouse_hook(int button, int x, int y);
int		get_next_line(int const fd, char **line);
int		get_next_map(t_data *data, char *map);
void	draw(t_data *data);
void	init(t_data **data, char *map);
void	set_down(t_data *data);
t_node	*end(t_node *map);
t_point	*new_point(float x, float y, float z);

#endif
