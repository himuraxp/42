/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:35:53 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/25 16:44:06 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_printable_dir(t_data *data_lst)
{
	t_data			*print_lst;

	if (g_flags[FLAG_A])
		print_lst = data_lst;
	else if (g_flags[FLAG_AA])
		print_lst = lst_exclude(data_lst, &is_tree_dir);
	else
		print_lst = lst_exclude(data_lst, &is_hidden);
	print_data_lst(print_lst);
	if (!g_flags[FLAG_A])
		lst_pseudo_free(print_lst);
}
