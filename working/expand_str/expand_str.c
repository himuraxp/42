/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:33:31 by ylarbi            #+#    #+#             */
/*   Updated: 2016/05/09 14:54:55 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	expand_str(char *str)
{
	int i;
	int space;
	int start;

	i = 0;
	space = 0;
	start = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '	')
		{
			space = 1;
			if (start == 1)
				start = 2;
			i++;
		}
		else
		{
			if (start == 2 && space == 1)
			{
				write(1, "   ", 3);
				space = 0;
			}
			write(1, &str[i], 1);
			start = 1;
			i++;
		}
	}
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
		expand_str(av[1]);
	return (0);
}
