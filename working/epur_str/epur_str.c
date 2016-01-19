/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:30:22 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/18 20:09:11 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	epur_str(char *str)
{
	int i;
	int	space;
	int	start;

	start = 0;
	i = 0;
	space = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '	')
		{
			space = 1;
			if (start == 1)
				start = 2;
		}
		else
		{
			if (space == 1 && start == 2)
			{
				write(1, " ", 1);
				space = 0;
			}
			write(1, &str[i], 1);
			start = 1;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
		epur_str(av[1]);
	return (0);
}
