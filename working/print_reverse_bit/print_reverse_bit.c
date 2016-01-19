/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_reverse_bit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 08:52:24 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/19 08:56:08 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	reverse_bit(unsigned char octet)
{
	unsigned char	tmp;
	int				i;

	i = 0;
	tmp = 0;
	while (i < 8)
	{
		tmp |= ((octet >> i) & 1) << (7 - i);
		i++;
	}
	return (tmp);
}
