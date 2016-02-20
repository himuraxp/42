/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:16:25 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/28 15:39:44 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*swap;

	swap = (void*)malloc(len);
	if (swap)
	{
		ft_memcpy(swap, src, len);
		ft_memcpy(dst, swap, len);
		free(swap);
		return (dst);
	}
	return (NULL);
}
