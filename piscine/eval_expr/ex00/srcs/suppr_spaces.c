/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suppr_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 11:01:09 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/26 11:02:53 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_f.h"

char	*suppr_spaces(char *str)
{
	int		i;
	int		j;
	char	*swap;

	i = 0;
	j = 0;
	swap = malloc(ft_strlen(str) + 1);
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			swap[j] = str[i];
			j++;
		}
		i++;
	}
	swap[j] = '\0';
	return (swap);
}
