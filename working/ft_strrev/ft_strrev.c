/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 14:26:25 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/18 15:26:10 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strrev(char *str)
{
	int i;
	int len;
	char tmp;

	i = 0;
	len = 0;
	if (str)
	{
		len = ft_strlen(str) - 1;
		while (i <= len / 2)
		{
			tmp = str[i];
			str[i] = str[len - i];
			str[len - i] = tmp;
			i++;
		}
	}
	return (str);
}

int		main(int ac, char **av)
{
	char *str;

	str = malloc(sizeof(char) * ft_strlen(av[1]));
	if (ac != 2)
		return (0);
	str = ft_strrev(av[1]);
	printf("%s\n", str);
	return (0);
}
