/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:32:24 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/18 12:50:03 by ylarbi           ###   ########.fr       */
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

int main(int ac, char **av)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		alpha_mirror(av[1]);
		write(1, "\n", 1);
	}
	return (0);
}
