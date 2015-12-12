/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:05:06 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/06 19:14:41 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	len;
	unsigned int	count1;
	unsigned int	count2;
	char			*buf;

	count1 = 0;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if ((buf = (char *)malloc(sizeof(char *) * len + 1)) == NULL)
			return (NULL);
		while (count1 < len && s1[count1] != '\0')
		{
			buf[count1] = s1[count1];
			count1++;
		}
		count2 = 0;
		while (count1 < len && s2[count2] != '\0')
			buf[count1++] = s2[count2++];
		buf[count1] = '\0';
		return (buf);
	}
	return (0);
}
