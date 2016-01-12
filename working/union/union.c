/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:42:48 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/12 09:30:27 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_union(char *s1, char *c)
{
	int	i;
	int	j;

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

int		main(int argc, char **argv)
{
	char	c[128];

	c[0] = 0;
	if (argc == 3)
	{
		ft_union(argv[1], c);
		ft_union(argv[2], c);
	}
	write(1, "\n", 1);
	return (0);
}
