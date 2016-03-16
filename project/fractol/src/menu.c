/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:52:25 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/16 14:12:41 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_menu(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, 30, 0xFFFFFFFF
		, "Iteration = +/-");
	mlx_string_put(e->mlx, e->win, 20, 60, 0xFFFFFFFF
		, "Move = Up/Down/Left/Right");
	mlx_string_put(e->mlx, e->win, 20, 90, 0xFFFFFFFF
		, "Zoom = Scroll");
	mlx_string_put(e->mlx, e->win, 20, 120, 0xFFFFFFFF
		, "Spectre Color = 3/4");
	mlx_string_put(e->mlx, e->win, 20, 150, 0xFFFFFFFF
		, "Degrad Color = 1/2");
	mlx_string_put(e->mlx, e->win, 20, 180, 0xFFFFFFFF
		, "Exit = Echap");
}
