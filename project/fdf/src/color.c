/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 22:03:41 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/13 22:05:49 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(t_color *color)
{
	int	result;

	result = 0;
	color->r = 0xFF0000;
	color->v = 0x00FF00;
	color->b = 0x0000FF;
	result = color->r + color->v + color->b;
	return (result);
}

