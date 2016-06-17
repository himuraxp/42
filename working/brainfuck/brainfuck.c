/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 12:43:32 by ylarbi            #+#    #+#             */
/*   Updated: 2016/06/07 13:37:55 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "brainfuck.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	brainfuck(char *op)
{
	int		i;
	int		count;
	char	*brain;

	i = 0;
	count = 0;
	if (!(brain = (char*)malloc(sizeof(*brain) * 2048)))
		return ;
	while (i < 2048)
		brain[i++] = 0;
	i = 0;
	while (op[i])
	{
		if (op[i] == '>')
			brain++;
		else if (op[i] == '<')
			brain--;
		else if (op[i] == '+')
			(*brain)++;
		else if (op[i] == '-')
			(*brain)--;
		else if (op[i] == '.')
			ft_putchar(*brain);
		else if (op[i] == '[' && (*brain) == 0)
		{
			count = 1;
			while (count)
			{
				i++;
				if (op[i] == '[')
					count++;
				else if (op[i] == ']')
					count--;
			}
		}
		else if (op[i] == ']')
		{
			count = 1;
			while (count)
			{
				i--;
				if (op[i] == '[')
					count--;
				else if (op[i] == ']')
					count++;

			}
			i--;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		brainfuck(av[1]);
	else
		ft_putchar('\n');
	return (0);
}
