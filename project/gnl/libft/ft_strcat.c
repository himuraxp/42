/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:11:34 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/02 14:59:15 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int len_s1;
	int count;

	count = 0;
	len_s1 = ft_strlen(s1);
	while (s2[count] != '\0')
	{
		s1[len_s1] = s2[count];
		count++;
		len_s1++;
	}
	s1[len_s1] = '\0';
	return (s1);
}
