/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:05:10 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/04 16:19:41 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*new;

	if ((new = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1))) == NULL)
		return (NULL);
	ft_strcpy(new, s1);
	return (new);
}
