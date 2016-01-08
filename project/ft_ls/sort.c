/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:28:21 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/08 18:32:57 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data				*sort(t_data *data_lst, int (*f)(t_data *, t_data *))
{
	t_data			*new;
	char			found;

	if (!data_lst)
		return (NULL);
	new = NULL;
	lst_push_data(lst_copy_data(data_lst), &new);
	data_lst = data_lst->next;
	while (data_lst)
	{
		found = 0;
		while (!found)
		{
			found = ft_sort_hack(new, data_lst, f);
			if (!new->next)
				break ;
			new = new->next;
		}
		if (!found)
			lst_insert_after(lst_copy_data(data_lst), new);
		data_lst = data_lst->next;
		new = lst_find_head(new);
	}
	return (new);
}

int					sort_by_d_name(t_data *data1, t_data *data2)
{
	return (ft_strcmp(data1->d_name, data2->d_name));
}

int					sort_by_mtime(t_data *data1, t_data *data2)
{
	if (data2->stat->st_mtimespec.tv_sec
		== data1->stat->st_mtimespec.tv_sec)
		return (sort_by_d_name(data1, data2));
	return (data2->stat->st_mtimespec.tv_sec
	- data1->stat->st_mtimespec.tv_sec);
}

int					sort_by_birthtime(t_data *data1, t_data *data2)
{
	if (data2->stat->st_birthtime == data1->stat->st_birthtime)
		return (sort_by_d_name(data1, data2));
	return (data2->stat->st_birthtime - data1->stat->st_birthtime);
}

int					sort_by_ctime(t_data *data1, t_data *data2)
{
	if (data2->stat->st_ctime == data1->stat->st_ctime)
		return (sort_by_d_name(data1, data2));
	return (data2->stat->st_ctime - data1->stat->st_ctime);
}
