/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:53:23 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/03 13:47:10 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_hidden(char *str)
{
	if (str[0] == '.')
		return (1);
	return (0);
}

void	ft_ls(char *path, char *arg)
{
	struct dirent	*play;
	DIR				*rep;

	if(path != NULL)
		rep = opendir(path);
	else
		rep = opendir(".");
	while ((play = readdir(rep)))
	{
		if(arg != NULL && (ft_strcmp(arg, "-a") == 0))
		{
			ft_putstr(play->d_name);
			ft_putstr("\t");
		}
		else
		{
			if(ft_ls_hidden(play->d_name) == 0)
			{
				ft_putstr(play->d_name);
				ft_putstr("\t");
			}
		}
	}
	closedir(rep);
}
