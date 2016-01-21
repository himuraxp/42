/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:26:06 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/21 18:46:40 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_basic_file(t_data *file)
{
	color_dir(file);
	color_xusr_active(file);
	color_link(file);
	print_name_stop_color(file);
	if (g_flags[FLAG_P] && file->type == T_DIR)
		ft_putchar('/');
	ft_putchar('\n');
}

void				print_detailled_file(t_data *file, int *width)
{
	int				device_len;

	device_len = (width[HAS_DEVICE]) ? width[P_MAJOR] + width[P_MINOR] + 3
		: width[FILE_SIZE];
	print_permissions(file);
	print_nbr_col(file->stat->st_nlink, width[NLINK]);
	print_user_group(file, width);
	if (file->type == T_CHR || file->type == T_BLK)
		print_device(file, width);
	else
		print_nbr_col(file->stat->st_size, device_len);
	print_which_date(file->stat);
	color_dir(file);
	color_xusr_active(file);
	if (file->type == T_LNK)
	{
		color_link(file);
		print_name_stop_color(file);
		print_pointed_dir(file);
	}
	else
		print_name_stop_color(file);
	if (g_flags[FLAG_P] && file->type == T_DIR)
		ft_putchar('/');
	ft_putchar('\n');
}

void				print_char_col(char *col, int width)
{
	int				len;

	len = ft_sizelen(col);
	ft_putstr(col);
	while (width-- - len >= 0)
		ft_putchar(' ');
}

void				print_nbr_col(int nb, int width)
{
	int				len;

	len = ft_intlen(nb);
	while (width-- - len >= 0)
		ft_putchar(' ');
	ft_putnbr(nb);
	ft_putchar(' ');
}

void				print_which_date(t_stat *stat)
{
	if (g_flags[FLAG_UU])
		print_date(stat->st_birthtime);
	else if (g_flags[FLAG_C])
		print_date(stat->st_ctime);
	else if (g_flags[FLAG_U])
		print_date(stat->st_atime);
	else
		print_date(stat->st_mtimespec.tv_sec);
}
