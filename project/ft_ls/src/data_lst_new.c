/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_lst_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:35:43 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/25 16:52:29 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data			*lst_new_data(char *d_name, char *path)
{
	int			result;
	t_data		*new;
	t_stat		temp;

	if(!((new = (t_data*)malloc(sizeof(t_data)))
		&& (new->stat = (t_stat*)malloc(sizeof(t_stat)))))
		exit(EXIT_FAILURE);
	result = lstat(path, new->stat);
	if (g_settings[S_CALL] == 0 && g_flags[FLAG_L] == 0 && result == 0
		&& lst_data_type(new->stat) == T_LNK && stat(path, &temp) == 0
		&& lst_data_type(&temp) == T_DIR)
		result = stat(path, new->stat);
	new->error = NULL;
	if (result == -1)
	{
		new->type = T_ERROR;
		new->error = strerror(errno);
	}
	else
		new->type = lst_data_type(new->stat);
	new->d_name = d_name;
	new->path = path;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void			lst_push_data(t_data *data, t_data **data_lst)
{
	if (data_lst)
	{
		data->prev = NULL;
		data->next = *data_lst;
		if (*data_lst)
			(*data_lst)->prev = data;
		*data_lst = data;
	}
}

void			lst_insert_before(t_data *insert, t_data *here)
{
	insert->next = here;
	insert->prev = here->prev;
	here->prev = insert;
	if (insert->prev)
		insert->prev->next = insert;
}

void			lst_insert_after(t_data *insert, t_data *here)
{
	insert->next = here->next;
	insert->prev = here;
	here->next = insert;
	if (insert->next)
		insert->next->prev = insert;
}

int				lst_count(t_data *data_lst)
{
	int			count;

	count = 0;
	while (data_lst)
	{
		count++;
		data_lst = data_lst->next;
	}
	return (count);
}
