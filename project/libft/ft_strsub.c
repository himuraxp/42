/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:04:53 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/02 15:36:08 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	count;

	count = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	if ((buf = (char *)malloc(sizeof(*buf) * (len + 1))) == NULL)
		return (NULL);
	{
		while (count < len && s[start] != '\0')
		{
			buf[count] = s[start];
			start++;
			count++;
		}
		buf[count] = '\0';
	}
	return (char *)(buf);
}
