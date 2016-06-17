/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:30:55 by ylarbi            #+#    #+#             */
/*   Updated: 2016/05/09 13:14:56 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	epur_str(char *str)
{
	int i;
	int start;
	int space;
	int len;

	space = 0;
	start = 0;
	i = 0;
	len = ft_strlen(str);
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '	')
		{
			space = 1;
			if (start == 1)
				start = 2;
		}
		else
		{
			if (space == 1 && start == 2)
			{
				write(1, " ", 1);
				space = 0;
			}
			write(1, &str[i], 1);
			start = 1;
		}
		i++;
	}
	if (len == i)
		write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
		epur_str(av[1]);
	return (0);
}
