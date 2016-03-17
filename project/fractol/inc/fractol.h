/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:51:03 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/17 09:23:27 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

typedef struct	s_env
{
	int			b;
	int			g;
	int			r;
	int			x;
	int			y;
	int			iter;
	int			filter;
	int			len;
	int			bit;
	int			end;
	char		*fractol;
	char		*img_addr;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		img_x;
	double		img_y;
	double		c_r;
	double		c_i;
	double		v_r;
	double		v_i;
	double		z_r;
	double		z_i;
	void		*img;
	void		*mlx;
	void		*win;
}				t_env;

int				expose_hook(t_env *e);
int				motion(int x, int y, t_env *e);
int				mouse(int key, int x, int y, t_env *e);
int				key(int key, t_env *e);
int				mandelbrot(t_env *e);

char			*arg_convert(char *av);

void			init(t_env *e, char *str);
void			init_mandelbrot(t_env *e);
void			ft_draw(t_env *e);
void			ft_draw_menu(t_env *e);
void			ft_error(int error);
void			display(t_env *e, int blue, int green, int red);
void			display_mandelbrot(t_env *e);
void			display_julia(t_env *e);
void			zoom(t_env *e, int x, int y, int key);
void			move(t_env *e, int key);
void			color(t_env *e, int key);

#endif
