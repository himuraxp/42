/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:53:45 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/27 03:40:22 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH	1400
# define HEIGHT	1400

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <mlx.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include "libft.h"
#include "get_next_line.h"
#include "color.h"

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct  s_line
{
	int 		x0;
	int 		x1;
	int 		y0;
	int 		y1;
	int 		z;
	int         z1;
	int 		z2;
	int 		color;
}				t_line;

typedef struct	s_data
{
	int 		**map;
 	void 		*img;
	char		*addr;
	int 		bpp;
	int			s_line;
	int 		endian;
	int			x;
	int			y;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			start_x;
	int			start_y;
	int 		nb_p;
	int 		zoom_z;
	int 		zoom_x;
	int 		zoom_y;
	int 		move_down;
	int 		move_right;
	int 		pal;
}				t_data;

int		ft_fdf(char *av);
void	ft_draw(t_data *d);
int		ft_strcount(char const *s, char c);
void    error_param(char *str, int error);
void	init(t_data *data, char *map);
void    verif_valid(char *map);
void    check_len(t_data *data, char* map);

#endif
