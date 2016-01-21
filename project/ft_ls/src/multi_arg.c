/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:02:57 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/08 16:05:12 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				has_extended_attr(char *path)
{
	int			count;

	count = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (count > 0)
		return (1);
	else
		return (0);
}
