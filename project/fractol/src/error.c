/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:39:40 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/17 11:34:53 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*arg_convert(char *av)
{
	char *str;
	if (ft_strncmp(av, "-m", 2))
		str = ft_strdup("mandelbrot");
	else if (ft_strncmp(av, "-j", 2))
		str = ft_strdup("julia");
	else
		str = av;
	return (str);
}

void	ft_error(int error)
{
	if (error == 0)
		ft_putendl("\033[31;1merror : invalid number of arguments\033[0m");
	if (error == 1)

		ft_putendl("\033[31;1merror : invalid argument\033[0m");
	ft_putendl("list of valid arguments :\n");
	ft_putendl("\t\t\t\033[1;30m-->\033[32;1Mandelbrot");
	ft_putendl("\t\t\t\033[1;30m-->\033[32;1\t\t\t-> Julia");
	ft_putendl("\t\t\t\033[1;30m-->\033[32;1\t\t\t-> Carpet\033[0m");
	exit(0);
}
