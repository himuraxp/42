/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 16:35:38 by chdenis           #+#    #+#             */
/*   Updated: 2015/07/26 19:21:13 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "check.h"
#include "fts.h"

int		col_count(char *str)
{
	int i;
	int count;
	int last;

	last = -1;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (last > -1 && last != count)
				return (-1);
			last = count;
			count = 0;
		}
		else
			count++;
		i++;
	}
	return (last);
}

int		lines_count(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

void	print_colle(int colle, int col, int lin)
{
	ft_putstr("[colle-0");
	ft_putnbr(colle);
	ft_putstr("] [");
	ft_putnbr(col);
	ft_putstr("] [");
	ft_putnbr(lin);
	ft_putstr("]");
}

int		process_check(char **lines, int lin, int col)
{
	int i;
	int again;
	int j;

	i = 0;
	again = 0;
	while (i < 5)
	{
		if (check(lines, lin, i))
		{
			if (again)
				ft_putstr(" || ");
			print_colle(i, col, lin);
			again = 1;
		}
		i++;
	}
	if (again)
		return (1);
	j = 0;
	while (j < lin)
		free(lines[j++]);
	free(lines);
	return (0);
}

int		parse(char *str)
{
	char	**lines;
	int		len_lin;
	int		len_col;
	int		i;
	int		j;

	if (str[0] == '\0' || str[0] == '\n'
		|| (len_col = col_count(str)) == -1
		|| (len_lin = lines_count(str)) == 0)
		return (0);
	lines = (char**)malloc(sizeof(char*) * len_lin);
	i = 0;
	while (i < len_lin)
	{
		lines[i] = (char*)malloc(sizeof(char) * (len_col + 1));
		j = 0;
		while (str[j + ((len_col + 1) * i)] != '\n')
		{
			lines[i][j] = str[j + ((len_col + 1) * i)];
			j++;
		}
		lines[i][j] = '\0';
		i++;
	}
	return (process_check(lines, len_lin, len_col));
}
