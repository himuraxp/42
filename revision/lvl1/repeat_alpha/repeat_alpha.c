/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 17:29:54 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/29 19:07:42 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putcharv2(char c, int i)
{
	while (i-- > 0)
	{
		write(1, &c, 1);
	}
}

void	repeat_alpha(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			count = str[i] - 96;
		else if (str[i] >= 'a' && str[i] <= 'z')
			count = str[i] - 64;
		else
			count = 1;
		ft_putcharv2(str[i], count);
		i++;
	}
}
