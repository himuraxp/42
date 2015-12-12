/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alphav2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 22:15:50 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/29 22:35:22 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_alpha(char c, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		write(1, &c, 1);
		i++;
	}
}

void	repeat_alpha(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			count = str[i] - 64;
		else if (str[i] >= 'a' && str[i] <= 'z')
			count = str[i] - 96;
		print_alpha(str[i], count);
		i++;
	}
}
