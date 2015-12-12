/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 12:00:54 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/31 15:11:33 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i;
	char result[8];
	int  j;

	i = 0;
	j = 128;
	while (i < 8)
	{
		if ((octet / j) == 0)
			result[i] = '0';
		else
		{
			octet = octet % j;
			result[i] = '1';
		}
		i++;
		j = j / 2;
	}
	write(1, &result, 8);
}
