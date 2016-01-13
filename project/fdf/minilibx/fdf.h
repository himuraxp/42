/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:53:45 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/13 14:48:18 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <sys/types.h>
#include <sys/uio.h>

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

typedef struct	s_color
{
	int		r;
	int		v;
	int		b;
}				t_color;

int		ft_fdf(char *av);

#endif
