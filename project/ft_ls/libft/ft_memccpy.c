/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:01:39 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/02 16:56:58 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst1;
	const unsigned char	*src1;
	size_t				count;

	count = 0;
	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	while (count < n)
	{
		dst1[count] = src1[count];
		if (src1[count] == (unsigned char)c)
			return (&(dst1[count + 1]));
		count++;
	}
	return (NULL);
}
