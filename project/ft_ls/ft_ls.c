/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:18:55 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/12 11:04:01 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*g_flags;
int				*g_settings;

void			get_shell_size(void)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	g_settings[S_WIN_COLS] = w.ws_col;
	g_settings[S_WIN_ROWS] = w.ws_row;
}

int				main(int ac, char **av)
{
	t_data		*arg_lst;

	g_flags = (char*)malloc(sizeof(char) * 17);
	bzero(g_flags, sizeof(char) * 17);
	g_settings = (int*)malloc(sizeof(int) * 6);
	bzero(g_settings, sizeof(int) * 6);
	get_shell_size();
	arg_lst = NULL;
	parse(ac - 1, av + 1, &arg_lst);
	if (!arg_lst)
		lst_push_data(lst_new_data(ft_strdup("."), ft_strdup(".")), &arg_lst);
	g_settings[S_NB_ARGS] = lst_count(arg_lst);
	initialize(arg_lst);
	return (g_settings[S_RETURN]);
}
