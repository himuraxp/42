/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 00:14:16 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/19 22:09:58 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"
#include <stdio.h>

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (*str != 0x00)
	{
		count++;
		str++;
	}
	return (count);
}

int		linecmp(char *str)
{
	int i;
	int j;

	j = -1;
	i = -1;
	while (++i < 9)
	{
		while (++j < 9)
			if (i != j)
				if ((*(str + i) == *(str + j)) && *(str + i) != '.')
					return (1);
		j = -1;
	}
	return (0);
}

int		rowcmp(char **str)
{
	int i;
	int j;
	int k;

	j = -1;
	i = -1;
	k = -1;
	while (++k < 9)
	{
		while (++i < 9)
		{
			while (++j < 9)
				if (i != j)
				{
					if (*(*(str + i + 1) + k) == *(*(str + j + 1) + k))
						if (*(*(str + i + 1) + k) != '.')
						{
							return (1);
						}
				}
			j = -1;
		}
		i = -1;
	}
	return (0);
}

int		error(int argc, char *argv[])
{
	int i;

	i = argc;
	if (argc != 10)
	{
		write(1, "Erreur\n", 7);
		return (1);
	}
	i = 0;
	while (++i < 10)
	{
		if (ft_strlen(argv[i]) != 9 || linecmp(argv[i]))
		{
			write(1, "Erreur\n", 7);
			return (1);
		}
	}
	if (rowcmp(argv) || blockcmp(argv))
	{
		write(1, "Erreur\n", 8);
		return (1);
	}
	return (0);
}

void	print_error(void)
{
	write (1, "Erreur\n", 7);
}
