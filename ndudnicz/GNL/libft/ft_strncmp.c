/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:17:35 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/11/30 10:45:27 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	else if (*s1 && *s2 && (*s1 == *s2) && (n - 1) > 0)
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}
