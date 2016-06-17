/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ep.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:04:53 by ylarbi            #+#    #+#             */
/*   Updated: 2016/05/09 14:30:39 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	epur_str(char *str)
{
	int i;
	int space;
	int start;

	i = 0;
	space = 0;
	start = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '	')
		{
			space = 1;
			if (start == 1)
				start = 2;
			i++;
		}
		else
		{
			if (space == 1)
			{
				if (start == 2)
					write(1, " ", 1);
				space = 0;
				start = 1;
			}
			write(1, &str[i], 1);
			i++;
		}
	}
		write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
		epur_str(av[1]);
	return (0);
}
