/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:02:47 by ylarbi            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/12/27 11:21:30 by ylarbi           ###   ########.fr       */
=======
/*   Updated: 2015/12/22 20:35:37 by ylarbi           ###   ########.fr       */
>>>>>>> 4f42a4fe446ce3cdedb9b97a5e28297c741c7aaf
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (0);
}
