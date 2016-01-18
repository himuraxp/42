/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:29:00 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/18 16:18:08 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bit(unsigned char octet)
{
	int i;
	int j;
	char result[8];

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
		j = j / 2;
		i++;
	}
	write(1, &result, 8);
}
