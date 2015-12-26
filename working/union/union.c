/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:42:48 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/26 14:07:27 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_right(char *av1, char *av2)
{
	int i;

	i = 0;
	if (av1 && av2)
	{
		while (av1[i] != '\0')
			i++;
		i = 0;
		while (av2[i] != '\0')
			i++;
	}
	return (0);
}

void	ft_union(char *av1, char *av2)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (ft_right(av1, av2))
	{
		while (av1[j] || av2[j])
		{
			if (av1[i] == av1[j] || av2[i] == av2[j])
			break;
			j++;
		}
		write(1, &av1[i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_union(av[1], av[2]);
	return (0);
}
