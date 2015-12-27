/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:09:43 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/22 20:30:32 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*buffer;
	size_t	i;

	if ((buffer = (char *)malloc(size)) == 0)
		return (NULL);
	i = 0;
	while (i < size)
		buffer[i++] = 0;
	return (buffer);
}
