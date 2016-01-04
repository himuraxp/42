/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 12:44:15 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/06 19:21:55 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *s, size_t n)
{
	size_t	count;
	char	*str;

	count = 0;
	if (!(str = (char*)malloc(sizeof(*str) * (n + 1))))
		return (NULL);
	while (count < n)
	{
		str[count] = s[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
