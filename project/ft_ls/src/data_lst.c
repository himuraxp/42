/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:42:02 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/24 10:23:38 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_block_size(t_data *data_lst)
{
	quad_t			count;

	count = 0;
	while (data_lst)
	{
		count += data_lst->stat->st_blocks;
		data_lst = data_lst->next;
	}
	ft_putstr("total ");
	ft_putlnbr(count);
	ft_putchar('\n');
}

int					*lst_max_properties_length(t_data *data_lst)
{
	int				*max;
	int				len;

	if (!(max = (int*)malloc(sizeof(int) * 7)))
		exit(EXIT_FAILURE);
	bzero(max, sizeof(int) * 7);
	while (data_lst)
	{
		if (data_lst->type == T_CHR || data_lst->type == T_BLK)
			max[HAS_DEVICE] = 1;
		if ((len = ft_intlen(data_lst->stat->st_nlink)) > max[NLINK])
			max[NLINK] = len;
		if ((len = get_user_len(data_lst->stat)) > max[USER])
			max[USER] = len;
		if ((len = get_gr_len(data_lst->stat)) > max[GRP])
			max[GRP] = len;
		if ((len = ft_intlen(data_lst->stat->st_size)) > max[FILE_SIZE])
			max[FILE_SIZE] = len;
		if ((len = ft_intlen(major(data_lst->stat->st_rdev))) > max[P_MAJOR])
			max[P_MAJOR] = len;
		if ((len = ft_intlen(minor(data_lst->stat->st_rdev))) > max[P_MINOR])
			max[P_MINOR] = len;
		data_lst = data_lst->next;
	}
	return (max);
}

int					get_user_len(t_stat *stat)
{
	int				len;

	if (getpwuid(stat->st_uid))
		len = ft_strlen(getpwuid(stat->st_uid)->pw_name);
	else
		len = ft_intlen(stat->st_uid);
	return (len);
}

int					get_gr_len(t_stat *stat)
{
	int				len;

	if (getgrgid(stat->st_gid))
		len = ft_strlen(getgrgid(stat->st_gid)->gr_name);
	else
		len = ft_intlen(stat->st_gid);
	return (len);
}

int					get_name_len(t_data *lst)
{
	int				max;
	int				len;

	max = 0;
	while (lst)
	{
		if ((len = ft_strlen(lst->d_name)) > max)
			max = len;
		lst = lst->next;
	}
	return (max);
}
