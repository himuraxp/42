/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 14:52:57 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/30 15:06:35 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			s1[i] = s1[i] - s2[i];
		}
		i++;
	}
	return (i);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	printf("strcmp : %d\n", strcmp(argv[1], argv[2]));
	printf("ft_strcmp : %d\n", strcmp(argv[1], argv[2]));
	return (0);
}
