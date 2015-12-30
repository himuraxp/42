/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 07:43:55 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/11/30 11:05:44 by ndudnicz         ###   ########.fr       */
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
