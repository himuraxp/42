/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:51:03 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/15 18:07:48 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

typedef struct	s_env
{
	char	*fractol;
	int		im;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	img_x;
	double	img_y;
	void	*mlx;
	void	*win;
}				t_env;

void	init(t_env *e, char *str);
void	init_mandel(t_env *e);

#endif
