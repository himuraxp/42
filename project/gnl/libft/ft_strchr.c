/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:02:47 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/02 16:34:50 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	if (!*s || !c)
		return ((char*)s + len);
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char*)s + i);
		i++;
	}
	return (0);
}
