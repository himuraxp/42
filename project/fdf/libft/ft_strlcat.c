/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:30:51 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/02 16:36:59 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	size_src;
	size_t	size_dst;

	len = ft_strlen(dst);
	size_dst = len;
	size_src = 0;
	if (size < len)
		return (size + ft_strlen(src));
	while (size_dst < (size - 1) && src[size_src])
		dst[size_dst++] = src[size_src++];
	dst[size_dst] = '\0';
	return (ft_strlen(src) + len);
}
