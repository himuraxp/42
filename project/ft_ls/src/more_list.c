/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:42:42 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/08 17:26:02 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				lst_free(t_data *data_lst)
{
	t_data			*next;

	while (data_lst)
	{
		next = data_lst->next;
		free(data_lst->d_name);
		free(data_lst->path);
		if (data_lst->error == NULL)
			free(data_lst->stat);
		free(data_lst);
		data_lst = next;
	}
}

void				lst_pseudo_free(t_data *data_lst)
{
	t_data			*next;

	while (data_lst)
	{
		next = data_lst->next;
		free(data_lst);
		data_lst = next;
	}
}

t_data				*lst_copy_data(t_data *data)
{
	t_data			*new;

	new = (t_data*)malloc(sizeof(t_data));
	ft_memcpy(new, data, sizeof(t_data));
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_data				*lst_find_head(t_data *data_lst)
{
	if (!data_lst)
		return (NULL);
	while (data_lst->prev)
		data_lst = data_lst->prev;
	return (data_lst);
}

int					lst_data_type(t_stat *stat)
{
	if (S_ISDIR(stat->st_mode))
		return (T_DIR);
	else if (S_ISCHR(stat->st_mode))
		return (T_CHR);
	else if (S_ISBLK(stat->st_mode))
		return (T_BLK);
	else if (S_ISREG(stat->st_mode))
		return (T_FILE);
	else if (S_ISFIFO(stat->st_mode))
		return (T_FIFO);
	else if (S_ISLNK(stat->st_mode))
		return (T_LNK);
	return (T_SOCK);
}
