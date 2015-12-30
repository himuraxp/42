/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:28:05 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/11/30 10:39:47 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*new_dst;
	unsigned char	*new_src;

	new_dst = (unsigned char*)dst;
	new_src = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		*new_dst = *new_src;
		if (*new_src == (unsigned char)c)
		{
			return (new_dst + 1);
		}
		i++;
		new_dst++;
		new_src++;
	}
	return (NULL);
}
