/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:23:19 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/17 17:45:15 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_fdf(char *map)
{
	t_data	*data;
	ft_putstr("ft_fdf start\n");
	ft_putstr("ft_fdf -> init\n");
	init(&data, map);
	ft_putstr("ft_fdf -> draw\n");
	draw(data);
	ft_putstr("ft_fdf -> mlx_key_hook\n");
	mlx_key_hook(data->win, key_hook, data);
	ft_putstr("ft_fdf -> mlx_mouse_hook\n");
	mlx_mouse_hook(data->win, mouse_hook, data);
	ft_putstr("ft_fdf -> mlx_loop\n");
	mlx_loop(data->mlx)
	ft_putstr("ft_fdf end\n");
	return (EXIT_SUCCESS);
}
