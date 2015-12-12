/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/24 13:44:08 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/24 15:08:45 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	epur_str(char *str)
{
	int i;
	int space;
	int start;

	start = 0;
	i = 0;
	space = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i]  == '	')
		{
			space = 1;
			if (start == 1)
				start = 2;
		}
		else
		{
			if	(space == 1 && start == 2)
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
	if (ac == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	epur_str(av[1]);
	return (0);
}
