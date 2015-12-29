/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:27:27 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/29 13:36:21 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *str)
{
	char	*new;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	if (!(new = (char *)malloc(sizeof(str) * len + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (0);
}
