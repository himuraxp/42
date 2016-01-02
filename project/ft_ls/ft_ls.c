/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:53:23 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/02 19:08:47 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(char *path)
{
	struct dirent	*play;
	DIR				*rep;

	if(path != NULL)
		rep = opendir(path);
	else
		rep = opendir(".");
	while ((play = readdir(rep)))
	{
		ft_putstr(play->d_name);
		ft_putstr("\n");
	}
	closedir(rep);
}
