/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linecmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:23:26 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/15 17:51:38 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_linecmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (((ft_islower(s1[i]) && s1[i] == s2[i] + 32) ||
			(ft_isupper(s1[i]) && s1[i] == s2[i] - 32) ||
			(s1[i] == s2[i])) && (s1[i] || s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
