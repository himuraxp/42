/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 08:14:00 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/11/30 10:40:22 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*new_dst;
	char	*new_src;

	if (!n || dst == src)
		return (dst);
	new_dst = (char*)dst;
	new_src = (char*)src;
	while (--n)
	{
		*new_dst++ = *new_src++;
	}
	*new_dst = *new_src;
	return (dst);
}
