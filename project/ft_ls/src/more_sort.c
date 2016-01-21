/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 18:00:19 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/08 18:04:00 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					sort_by_atime(t_data *data1, t_data *data2)
{
	if (data2->stat->st_atime == data1->stat->st_atime)
		return (sort_by_d_name(data1, data2));
	return (data2->stat->st_atime - data1->stat->st_atime);
}

int					sort_by_size(t_data *data1, t_data *data2)
{
	return (data2->stat->st_size - data1->stat->st_size);
}

int					sort_f(void)
{
	return (1);
}
