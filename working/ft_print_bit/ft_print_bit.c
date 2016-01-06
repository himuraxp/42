/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 22:18:51 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/04 22:52:20 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_print_bit(unsigned char octet)
{
	int	i;
	char c;

	i = 0;
	while (i < 8)
	{
		c = ((octet >> (7 - i)) & 1) + 48;
		write(1, &c, 1);
		i++;
	}
	write(1, '\n', 1);
}
