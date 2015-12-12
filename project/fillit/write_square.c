/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 03:54:12 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/10 04:24:35 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_write_square(t_global *global)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < global->size)
	{
		while (x < global->size)
		{
			write (1, &global->square[y][x], 1);
			x++;
		}
		y++;
		x = 0;
		write (1, "\n", 1);
	}
}
