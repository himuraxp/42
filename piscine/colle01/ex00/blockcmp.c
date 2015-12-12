/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blockcmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 20:03:45 by mfroehly          #+#    #+#             */
/*   Updated: 2015/07/19 22:09:18 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

char	*block_to_line(char **argv, int x, int y)
{
	int		i;
	int		j;
	char	temp;
	char	*line;

	i = -1;
	j = -1;
	x *= 3;
	y *= 3;
	line = malloc(sizeof(char) * 10);
	*(line + 9) = '\0';
	while (++i < 3)
	{
		while (++j < 3)
			*(line + (i * 3) + j) = *(*(argv + j + 1 + y) + i + x);
		j = -1;
	}
	return (line);
}

int		blockcmp(char **argv)
{
	int		x;
	int		y;
	char	*tmp;

	x = -1;
	y = -1;
	while (++x < 3)
	{
		while (++y < 3)
		{
			tmp = block_to_line(argv, x, y);
			if (linecmp(tmp))
			{
				return (1);
			}
			free(tmp);
		}
		y = -1;
	}
	return (0);
}
