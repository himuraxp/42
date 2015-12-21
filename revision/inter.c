/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:12:59 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/21 16:57:46 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	is_in_string(char *s2, char c)
{
	int i;

	i = 0;
	while (s2[i])
	{
		if (s2[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	is_first(char *s1, char c, int len)
{
	int i;

	i = 0;
	while (s1[i] && s1[i] != c)
		i++;
	if (i == len)
		return (1);
	return (0);
}

void		ft_inter(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (is_in_string(s2, s1[i]) && is_first(s1, s1[i], i))
			write(1, &s1[i], 1);
		i++;
	}
}

int			main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
