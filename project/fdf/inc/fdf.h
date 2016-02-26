/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:53:45 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/26 15:47:52 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH	1200
# define HEIGHT	800
# define ZOOM	10

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
	int			v;
	int			b;
}				t_color;

typedef struct	s_data
{
	int 		**map;
 	void 		*img;
	char		*addr;
	int 		bpp;
	int			size_line;
	int 		endian;
	int			x_map;
	int			y_map;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
}				t_data;

int		ft_fdf(char *av);
int		ft_strcount(char const *s, char c);
void    error_param(char *str, int error);
void	init(t_data *data, char *map);
void    verif_valid(char *map);
void    check_len(t_data *data, char* map);


#endif
