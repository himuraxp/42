/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 19:16:36 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/22 20:07:43 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_list_push_params(int ac, char **av)
{
	int i;
	t_list *list;

	i = 1;
	if (ac == 1)
		return (0);
	else
	{
		list = ft_create_elem(data);
		while (i <= ac)
		{
			list->data = av(i);
			list = list->next;
			i++;
		}
	}
	return (list);
}
