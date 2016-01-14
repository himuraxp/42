/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 20:00:57 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/13 22:12:57 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_data **data, char *map)
{
	if (!(*data = malloc(sizeof(t_data))))
		exit(-1);
	(*data)->mlx = mlx_init();
	if (!(*data)->mlx)
		exit(EXIT_FAILURE);
	(*data)->width = WIDTH;
	(*data)->height = HEIGHT;
	(*data)->win = mlx_new_window((*data)->mlx, WIDTH, HEIGHT, "FDF");
	if (!(*data)->win)
		exit(EXIT_FAILURE);
//	get_map(*data, map);
	if (map)
	{};
}

int		key_hook(int keycode)
{
	ft_putstr("key: ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 53)
		exit(0);
	return (0);

}
