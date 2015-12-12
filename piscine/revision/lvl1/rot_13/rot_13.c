/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 22:38:56 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/29 23:27:48 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rot(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'm')
				|| (str[i] >= 'A' && str[i] <= 'M'))
		{
			str[i] = str[i] + 13;
			write(1, &str[i], 1);
		}
		else if ((str[i] >= 'n' && str[i] <= 'z')
				|| (str[i] >= 'N' && str[i] <= 'Z'))
		{
			str[i] = str[i] - 13;
			write(1, &str[i], 1);
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	else
		rot(argv[1]);
	write(1, "\n", 1);
	return (0);
}
