/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:04:28 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/04 17:07:34 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(const char *s, char (*f)(char))
{
	int		count;
	char	*buf;

	count = 0;
	if (s)
	{
		if ((buf = (char *)malloc(sizeof(*buf) * (ft_strlen(s) + 1))) == NULL)
			return (NULL);
		while (s[count] != '\0')
		{
			buf[count] = f(s[count]);
			count++;
		}
		buf[count] = '\0';
		return (buf);
	}
	return (0);
}
