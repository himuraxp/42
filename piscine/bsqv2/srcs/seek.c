/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 17:45:56 by gmarguer          #+#    #+#             */
/*   Updated: 2015/07/30 23:08:24 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_seek2(t_seek *seek, char **array, int lvl)
{
	seek->y = seek->ymin;
	seek->x = seek->xmin;
	seek->tempx = seek->xmin;
	seek->tempy = seek->ymin;
	if (seek->y + seek->size > seek->ymax)
		return (0);
	while (seek->y <= seek->ymin + seek->size && seek->y <= seek->ymax)
	{
		while (seek->x <= seek->xmin + seek->size && seek->x <= seek->xmax)
		{
			if (array[seek->y][seek->x] == seek->used
				|| array[seek->y][seek->x] == '\n')
			{
				seek->xmin = seek->x;
				return (0);
			}
			seek->x += 1;
		}
		seek->x = seek->xmin;
		seek->y += 1;
	}
	seek->savex = seek->tempx;
	seek->savey = seek->tempy;
	seek->size += 1;
	return (ft_seek2(seek, array, lvl + 1));
}

void	ft_filling(t_read *read, t_seek *seek)
{
	int		x;
	int		y;

	x = seek->savex;
	y = seek->savey;
	while (y < seek->savey + seek->size)
	{
		while (x < seek->savex + seek->size)
		{
			read->array[y][x] = seek->filling;
			x++;
		}
		x = seek->savex;
		y++;
	}
}

int		ft_seek(t_read *read)
{
	t_seek	*seek;

	seek = ft_create_elem(read);
	while (seek->ymin < seek->ymax - seek->size)
	{
		while (seek->xmin < seek->xmax - seek->size)
		{
			if (read->array[seek->ymin][seek->xmin] == read->empty)
				ft_seek2(seek, read->array, 1);
			else if (read->array[seek->ymin][seek->xmin] != read->used)
				return (0);
			seek->xmin += 1;
		}
		seek->xmin = 0;
		seek->ymin += 1;
	}
	if (seek->savey == 0)
		return (0);
	ft_filling(read, seek);
	return (1);
}
