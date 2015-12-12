/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 23:52:22 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/30 13:53:07 by ylarbi           ###   ########.fr       */
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

void	alpha_mirror(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = 'z' - (str[i] - 'a');
			i++;
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = 'Z' - (str[i] - 'A');
			i++;
		}
	}
	ft_putstr(str);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		alpha_mirror(argv[1]);
		write(1, "\n", 1);
	}
	return (0);
}
