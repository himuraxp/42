/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 22:23:35 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/26 00:37:51 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_f.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
