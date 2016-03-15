/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:39:40 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/15 20:48:35 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int error)
{
	if (error == 0)
		ft_putendl("\033[31;1merror : invalid number of arguments\033[0m");
	if (error == 1)
		ft_putendl("\033[31;1merror : invalid argument\033[0m");
	ft_putendl("list of valid arguments :\n\t\t\t-> Mandelbrot\n\t\t\t-> Julia\n\t\t\t-> Carpet");
	exit(0);
}
