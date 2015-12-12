/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 15:54:53 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/30 16:45:36 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int i;
	char *str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	printf("%s\n", ft_strdup(argv[1]));
	printf("%s\n", strdup(argv[1]));
	return (0);
}
