/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:55:25 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/08 16:01:19 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			e_args_error(t_data *args)
{
	if (args)
		g_settings[S_RETURN] = 1;
	while (args)
	{
		e_file_error(args);
		args = args->next;
	}
}

void			e_file_error(t_data *file)
{
	ft_putstr_fd("ft_ls: ", 2);
	if (file->d_name[0] == '\0')
		ft_putstr_fd("fts_open", 2);
	else
		ft_putstr_fd(file->d_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(file->error, 2);
}

void			e_illegal_option(char opt)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(opt, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ./ft_ls [-1ARSTUacdfglprtu] [file ...]", 2);
	exit(1);
}