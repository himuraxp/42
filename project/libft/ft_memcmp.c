/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:02:32 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/02 16:57:15 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*ptr1;
	const unsigned char		*ptr2;
	size_t					i;

	i = 0;
	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	if (n <= 0)
		return (0);
	while (i < n && ptr1[i] == ptr2[i])
		i++;
	if (i < n || (i >= n && ptr1[i] == ptr2[i]))
		return (ptr1[i] - ptr2[i]);
	return (0);
}
