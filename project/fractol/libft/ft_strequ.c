/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 21:31:11 by ylarbi            #+#    #+#             */
/*   Updated: 2015/11/30 16:56:09 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *str1, char const *str2)
{
	int count;

	count = 0;
	if (str1 && str2)
	{
		while (str1[count] == str2[count] && str1[count] != '\0')
		{
			count++;
		}
		if (str1[count] == str2[count])
			return (1);
		else
			return (0);
	}
	return (0);
}
