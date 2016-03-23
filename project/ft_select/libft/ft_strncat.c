/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:42:55 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/02 15:01:02 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		len_dest;
	size_t	count;

	count = 0;
	len_dest = ft_strlen(s1);
	while (count < n)
	{
		s1[len_dest] = s2[count];
		count++;
		len_dest++;
	}
	s1[len_dest] = '\0';
	return (s1);
}
