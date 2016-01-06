/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 12:52:54 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/06 15:33:45 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"

struct		s_env
{
	void	*win;
	void	*mlx;
}			t_env;

int		ft_fdf(void);

#endif
