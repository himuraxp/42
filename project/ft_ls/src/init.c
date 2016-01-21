/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:33:56 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/12 11:02:19 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					initialize(t_data *arg_lst)
{
	t_data		*errors;
	t_data		*files;
	t_data		*dirs;

	errors = NULL;
	files = NULL;
	dirs = NULL;
	lst_filter(arg_lst, &errors, &files, &dirs);
	e_args_error(errors);
	print_data_lst(files);
	print_dirs(dirs);
	lst_free(errors);
	lst_free(files);
	return (0);
}
