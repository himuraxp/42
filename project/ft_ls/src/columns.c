/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:26:32 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/24 10:22:36 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_columns_data_lst(t_data *lst)
{
	int			*sizes;
	int			count;
	int			width;

	if (!lst)
		return ;
	if (!(sizes = (int*)malloc(sizeof(int) * 2)))
		exit(EXIT_FAILURE);
	bzero(sizes, sizeof(int) * 2);
	width = get_name_len(lst);
	count = lst_count(lst);
	sizes[1] = g_settings[S_WIN_COLS] / (width + 1);
	sizes[0] = (count + sizes[1] - 1) / sizes[1];
	print_mcolumns(lst, sizes, count, width);
}

void			print_mcolumns(t_data *lst, int *sizes, int count, int width)
{
	int			i;
	int			j;
	int			len;
	int			tmp;
	t_data		*file;

	i = -1;
	while (++i < sizes[0])
	{
		j = -1;
		tmp = sizes[1];
		while (++j < tmp)
		{
			if (j * sizes[0] + i >= count)
				continue ;
			file = lst_at(j * sizes[0] + i, lst);
			color_dir(file);
			color_xusr_active(file);
			color_link(file);
			print_name_stop_color(file);
			len = ft_strlen(file->d_name);
			if ((j + 1) * sizes[0] + i < count)
				while (len++ <= width)
					ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	free(sizes);
}
