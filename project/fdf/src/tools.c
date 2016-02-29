/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 16:49:31 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/29 18:09:04 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

void	color_black(t_color *c)
{
	c->r = 10;
	c->g = 10;
	c->b = 10;
	return ;
}

void	color_white(t_color *c)
{
	c->r = 200;
	c->g = 200;
	c->b = 200;
	return ;
}

double	max(double nb, double max)
{
	if (nb > max)
		return (max);
	return (nb);
}
