/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:05:25 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/06 12:35:42 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	while (ft_iswhite(s[i]) == 1)
		i++;
	while (ft_iswhite(s[len - 1]) == 1)
		len--;
	return (ft_strsub(s, i, (len != 0) ? len -= i : len));
}
