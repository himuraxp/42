/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:53:23 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/01 20:04:18 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
void	ft_stat(char *path)
{
	struct dirent	*play;
	struct stat		*info;
	DIR				*file;

	file = opendir(path);
	info = stat(info->st_rdev);
	while((play = readdir(file)))
	{
		ft_putstr(play->d_name);
		ft_putstr("\n");
	}
	{
		stat(info->st_rdev);
		ft_putstr("\n");
	}
	closedir(file);
}*/

void	ft_ls(char *path)
{
	struct dirent	*play;
	struct stat		info;
	DIR				*rep;

	if(path != NULL)
		rep = opendir(path);
	else
		rep = opendir(".");
	while ((play = readdir(rep)))
	{
		ft_putstr(play->d_name);
		ft_putnbr(stat(play->d_name, &info));
		ft_putstr("\n");
	}
	closedir(rep);
}
