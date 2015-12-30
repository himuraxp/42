/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:23:54 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/30 18:00:08 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = b;
	if (len == 0)
		return (b);
	else
	{
		while (len >= 1)
		{
			str[len - 1] = (unsigned char)c;
			len--;
		}
	}
	return (str);
}
