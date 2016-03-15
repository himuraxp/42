/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:44:28 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/04 16:03:48 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;
	char	*str_1;
	char	*str_2;

	count = 0;
	str_1 = (char *)src;
	str_2 = (char *)dst;
	while (count < n)
	{
		str_2[count] = str_1[count];
		count++;
	}
	return (dst);
}
