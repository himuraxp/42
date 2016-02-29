/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:53:45 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/29 16:57:24 by ylarbi           ###   ########.fr       */
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
int		ft_abs(int nb);
int		ft_atoi_i(const char *str, int *i);
int		expose_hook(t_data *data);
int		key_hook(int keycode, t_data *d);
int     mouse_hook(int button, int x, int y);
int		ft_strcount_word(char const *s, char c);
void 	move(int keycode, t_data *d);
void 	get_next_map(t_data *data);
void 	zoom(int keycode, t_data *data);
void 	zoom2(int keycode, t_data *data);
void	ft_draw(t_data *d);
void    error_param(char *str, int error);
void	init(t_data *data, char *map);
void    verif_valid(char *map);
void    create(t_data *d, int i, t_line	*l);
void    down_trace(int i, t_data *d, t_line *l);
void    right_trace(int i, t_data *d, t_line *l);
void	line(t_line *l, int dx, int dy, t_data *d);
void    check_len(t_data *data, char* map);
void    insert_map(t_data *data, int fd, int y, int x);
void    earth(int z, t_color *c);
void    random_f(t_line *l, t_data *d, t_color *c, int i);
void    random_e(t_line *l, t_data *d, t_color *c, int i);
void    random_d(t_line *l, t_data *d, t_color *c, int i);
void    random_c(t_line *l, t_data *d, t_color *c, int i);
void 	color_black(t_color *c);
void 	color_white(t_color *c);
void 	put_pxl(t_data *d, t_line *l, t_color *c);
double  max(double nb, double max);

t_color     *get_color(t_line *l, t_data *d, t_color *c, int i);

#endif
