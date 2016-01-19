/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:47:15 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/19 20:01:12 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_node		*end(t_node *map)
{
	t_node	*pos;

	pos = map;
	ft_putstr("end start\n");
	if(pos)
	{
		while(pos != NULL && pos->right != NULL)
		{
			pos = pos->right;
		}
	}
	ft_putstr("end end\n");
	return (pos);
}

void		set_down(t_data *data)
{
	t_node	*x;
	t_node	*y;
	t_node	*y_down;

	y = data->map;
	ft_putstr("set_down start\n");
	while (y)
	{
		y_down = y->down;
		x = y;
		while (x)
		{
			x->down = y_down ? y_down : NULL;
			x = x->right;
			y_down = y_down ? y_down->right : NULL;
		}
		y = y->down;
	}
	ft_putstr("set_down end\n");
}
