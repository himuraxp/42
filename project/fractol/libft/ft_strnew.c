/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:09:43 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/30 18:05:21 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t		i;
	char		*new_str;

	i = 0;
	if ((new_str = (char*)malloc(size)) == NULL)
		return (NULL);
	ft_bzero(new_str, size);
	return (new_str);
}
