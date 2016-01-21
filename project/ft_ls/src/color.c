/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:37:08 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/21 18:33:52 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_name_stop_color(t_data *file)
{
	ft_putstr(file->d_name);
	ft_putstr("\033[0m");
}

void	color_xusr_active(t_data *file)
{
	if (file->type == T_FILE && ((file->stat->st_mode & S_IXUSR) ? 1 : 0))
		ft_putstr("\033[31m");
}

void	color_dir(t_data *file)
{
	if (file->type == T_DIR)
		ft_putstr("\033[36m");
}

void	color_link(t_data *file)
{
	if (file->type == T_LNK)
		ft_putstr("\033[35m");
}
