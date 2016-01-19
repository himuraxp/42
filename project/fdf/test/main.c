/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 17:32:47 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/17 18:01:24 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int		main()
{
	void	*mlx;
	void	*win;
	int		y;
	int		x;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "test");
	y =	200;
/*	while (y < 600)
	{
		x = 200;
		while (x < 600)
		{
			x++;
		}
		y++;
	}*/
	mlx_pixel_put(mlx, win, y, x, 0x00FFFFFF);
	mlx_loop(mlx);
	return (0);
}
