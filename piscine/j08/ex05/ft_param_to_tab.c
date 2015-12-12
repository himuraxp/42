/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 15:46:58 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/20 20:11:47 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i++;
	return (i);
}

int					*ft_strdup(char *src)
{
	int				i;
	char			*dest;

	i = 0;
	if (dest == 0)
		return (0);
	dest = (char*)malloc(sizeof(*dest) * (ft_strlen(src) + 1));
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int				i;
	t_stock_par		*my_struct;

	i = 0;
	my_struct = malloc(sizeof(t_stock_par) * (ac + 1));
	while (i < ac)
	{
		my_struct[i]->size_param = ft_strlen(av[i]);
		my_struct[i]->str = av[i];
		my_struct[i]->copy = ft_strdup(av[i]);
		my_struct[i]->tab = ft_split_whitespaces(av[i]);
		i++;
	}
	my_struct[i]->str = 0;
}
