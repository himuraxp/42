/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 17:09:58 by chdenis           #+#    #+#             */
/*   Updated: 2015/07/25 20:54:20 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int		line_cmp(char *line, char start, char mid, char end)
{
	int col;
	int i;

	col = ft_strlen(line);
	if (line[0] != start)
		return (0);
	i = 1;
	while (i < col - 1)
	{
		if (line[i] != mid)
			return (0);
		i++;
	}
	if (col <= 1)
		return (1);
	return (line[col - 1] == end);
}

char	*line_chars(int colle)
{
	char *colle1;

	if (colle == 0)
		return ("o-o|o-o");
	if (colle == 2)
		return ("ABABCBC");
	if (colle == 3)
		return ("ABCBABC");
	if (colle == 4)
		return ("ABCBCBA");
	colle1 = (char*)malloc(sizeof(char) * 8);
	colle1[0] = '/';
	colle1[1] = '*';
	colle1[2] = '\\';
	colle1[3] = '*';
	colle1[4] = '\\';
	colle1[5] = '*';
	colle1[6] = '/';
	colle1[7] = 0;
	return (colle1);
}

int		check(char **lines, int len, int colle)
{
	int		i;
	char	*lin_c;

	lin_c = line_chars(colle);
	if (line_cmp(lines[0], lin_c[0], lin_c[1], lin_c[2]) == 0)
		return (0);
	i = 1;
	while (i < len - 1)
	{
		if (line_cmp(lines[i], lin_c[3], ' ', lin_c[3]) == 0)
			return (0);
		i++;
	}
	if (len <= 1)
		return (1);
	return (line_cmp(lines[len - 1], lin_c[4], lin_c[5], lin_c[6]));
}
