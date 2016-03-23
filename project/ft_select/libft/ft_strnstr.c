/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:03:19 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/02 15:10:05 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[count] && count < n)
	{
		if (s1[count] == s2[0] && !(i = 0))
			while (s1[count + i] == s2[i] && s1[count + i] && (count + i) < n)
			{
				i++;
				if (!s2[i])
					return ((char *)s1 + count);
			}
		count++;
	}
	return (NULL);
}
