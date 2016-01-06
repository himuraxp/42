/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:23:19 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/06 16:09:03 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(void *mlx, void *win)
{
	int	x;
	int y;

	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}


}

int		ft_fdf(void)
{
	t_env	*e;

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1920, 1080, "42");
	draw(e->mlx, e->win);
	mlx_loop(e->mlx);
	return (0);
}
