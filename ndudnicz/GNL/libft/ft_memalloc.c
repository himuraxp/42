/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:14:59 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/11/30 19:09:30 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*memory;

	i = 0;
	if ((memory = malloc(size)) == NULL || !size)
		return (NULL);
	while (i < size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
