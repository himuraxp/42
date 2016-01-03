/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 22:49:51 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/03 21:59:10 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_verif_path(char **av)
{
	if ((ft_strcmp(av[1], "-s") == 1) || (ft_strcmp(av[1], "-a") == 1))
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int i;

	i = ac;
	if (ac == 1)
	{
		ft_ls(".", NULL);
		return (0);
	}
	if (ac == 2 && (ft_verif_path(av) == 0))
	{
		ft_ls(av[1], NULL);
		return (0);
	}
	else if (!(ft_arg(ac, av, i) == 0))
		return (0);
/*	if ((ac == 3 && (ft_strcmp(av[1], "-a") == 0)) ||
			(ac == 2 && (ft_strcmp(av[1], "-a") == 0)))
		{
			if (ac == 2)
				ft_ls(".", av[1]);
			else
				ft_ls(av[i - 1], av[1]);
		}
	if (ac == 3 && (ft_strcmp(av[1], "-s") == 0))
		ft_stat(av[i - 1]);*/
	return (0);
}