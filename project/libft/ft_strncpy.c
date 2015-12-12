/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:50:02 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/02 16:38:57 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t size;

	size = 0;
	while (size < n && src[size] != '\0')
	{
		dst[size] = src[size];
		size++;
	}
	if (size < n)
		while (size < n)
		{
			dst[size] = '\0';
			size++;
		}
	return (dst);
}
