/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:39:40 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/18 10:59:20 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_dark(t_env *e)
{
	e->b -= (e->b > 4) ? 5 : 0;
	e->g -= (e->g > 4) ? 5 : 0;
	e->r -= (e->r > 4) ? 5 : 0;
}

void	color_light(t_env *e)
{
	e->b += (e->b < 254) ? 5 : 0;
	e->g += (e->g < 254) ? 5 : 0;
	e->r += (e->r < 254) ? 5 : 0;
}

void	ft_error(int error)
{
	if (error == 0)
		ft_putendl("\033[31;1merror : invalid number of arguments\033[0m");
	if (error == 1)
	{
		ft_putendl("\033[31;1merror : invalid argument\033[0m");
		ft_putendl("list of valid arguments :\n");
		ft_putendl("\t\t\t\033[1;30m  -->\033[32;1m Mandelbrot (-m)");
		ft_putendl("\t\t\t\033[1;30m  -->\033[32;1m Julia (-f)");
		ft_putendl("\t\t\t\033[1;30m  -->\033[32;1m Carpet (-c)\033[0m");
	}
	exit(0);
}

char	*arg_convert(char *av)
{
	char *str;

	if (ft_strcmp(av, "-m") == 0)
		str = ft_strdup("mandelbrot");
	else if (ft_strcmp(av, "-j") == 0)
		str = ft_strdup("julia");
	else if (ft_strcmp(av, "-c") == 0)
		str = ft_strdup("carpet");
	else
		str = av;
	return (str);
}
