/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:16:25 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/15 15:53:45 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_env *e, char *str)
{

}

int		main(int ac, char *ac)
{
	t_env	e;

	if (ac == 2)
	{
		init(&e, av[1]);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, e.image_x, e.image_y, "Fract'Ol");
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_hook(e.win, 6, (1L >> 0), &motion_notify, &e);
		mlx_hook(e.win, 4, (1L >> 0), &mouse_press, &e);
		mlx_hook(e.win, 2, (1L >> 0), &key_press, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_error(0);
	return (0);
}
