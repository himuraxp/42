/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 20:13:39 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/18 20:21:10 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_union(char *s1, char *c)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		j = 0;
		while (c[j] && s1[i] != c[j])
			j++;
		if (!c[j])
		{
			write(1, &s1[i], 1);
			c[j] = s1[i];
			c[j + 1] = 0;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	char c[128];

	c[0] = 0;
	if (ac == 3)
	{
		ft_union(av[1], c);
		ft_union(av[2], c);
	}
	write(1, "\n", 1);
	return (0);
}
