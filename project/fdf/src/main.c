/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 22:49:51 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/14 17:46:45 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include "fdf.h"
#include "get_next_line.h"

int		main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr("\033[31m map not found\033[0m");
		return (0);
	}
	if (ac == 2)
		ft_fdf(av[1]);
	return (0);
}
