/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 22:49:51 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/31 20:05:30 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>

int		main(void)
{
	struct	dirent *play;
	DIR *rep;

	rep = opendir(".");
	while ((play = readdir(rep)))
	{
		ft_putstr(play->d_name);
		ft_putstr("\n");
	}
	closedir(rep);
	return (0);
}
