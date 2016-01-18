/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 14:08:12 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/18 14:25:49 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int i;
	char *buf;

	i = 0;
	if (!(buf = malloc(sizeof(char) * ft_len(str) + 1)))
		return (0);
	while (str[i] != '\0')
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	printf("%s\n", ft_strdup(av[1]));
	return (0);
}
