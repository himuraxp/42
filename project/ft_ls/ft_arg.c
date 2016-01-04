/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 19:59:02 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/03 21:59:08 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_info(int ac, char **av, int i)
{
	if (ac == 3 && (ft_strcmp(av[1], "-s") == 0))
	{
		ft_stat(av[i - 1]);
		return (0);
	}
	return (1);
}

int		ft_all(int ac, char **av, int i)
{
	if (ft_strcmp(av[1], "-a") == 0)
	{
		if (ac == 3 || ac == 2)
		{
			if (ac == 2)
				ft_ls(".", av[1]);
			else
				ft_ls(av[i - 1], av[1]);
		}
		return (0);
	}
	return (1);
}

int		ft_arg(int ac, char **av, int i)
{
	if ((ft_all(ac, av, i) == 0))
		return (0);
	if ((ft_info(ac, av, i) == 0))
		return (0);


	return (1);
}
