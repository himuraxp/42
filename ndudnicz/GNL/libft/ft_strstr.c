/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:59:21 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/11/30 10:46:32 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		s2_len;
	size_t		s1_len;

	s1_len = ft_strlen(s1);
	if ((s2_len = ft_strlen(s2)) == 0)
		return ((char*)s1);
	while (s1_len >= s2_len && *s1)
	{
		s1_len--;
		if (!ft_strncmp(s1, s2, s2_len))
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
