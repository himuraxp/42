/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 22:03:41 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/17 17:09:24 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(t_color *color)
{
	int	result;
	ft_putstr("ft_color start\n");
	result = 0;
	color->r = 0x500000;
	color->v = 0x009900;
	color->b = 0x000012;
	result = color->r + color->v + color->b;
	ft_putstr("ft_color end\n");
	return (result);
}

