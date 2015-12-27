/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 15:13:38 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/26 11:00:25 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_min(char c)
{
	if (c >= 95 && c <= 122)
		return (1);
	return (0);
}

int		ft_maj(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

void	ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_maj(str[i]))
			str[i] += 32;
		if (str[i] == ' ')
		{
			write(1, &str[i], 1);
			if (ft_min(str[++i]))
				str[i] -= 32;
		}
		if (i == 0 && ft_min(str[i]))
				str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	ft_strcapitalize(av[1]);
	return (0);
}
