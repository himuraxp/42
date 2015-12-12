/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 20:54:47 by mfroehly          #+#    #+#             */
/*   Updated: 2015/07/19 22:11:45 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "grille.h"

void	init_grille_vide(char ***grille)
{
	int i;

	i = -1;
	*grille = malloc(sizeof(char *) * 9);
	while (++i < 9)
		*((*grille) + i) = malloc(sizeof(char) * 10);
}

int		ft_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		if (!((*src >= '0' && *src <= '9') || *src == '.'))
			return (0);
		*dest = *src;
		dest++;
		src++;
	}
	*(dest) = '\0';
	return (1);
}

int		init_grille(char **argv, char ***grille)
{
	int i;

	i = -1;
	*grille = malloc(sizeof(char *) * 9);
	while (++i < 9)
	{
		*((*grille) + i) = malloc(sizeof(char) * 10);
		if (!ft_strcpy(*((*grille) + i), *(argv + i + 1)))
			return (0);
	}
	return (1);
}

void	print_grille(char **grille)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++j < 9)
	{
		while (*(*grille) + ++i != '\0' && i < 9)
		{
			write(1, (*(grille + j) + i), 1);
			if (i < 8)
				write(1, " ", 1);
		}
		i = -1;
		write(1, "\n", 1);
	}
}

void	free_grille(char ***grille)
{
	int i;

	i = -1;
	while (++i < 9)
		free(*((*grille) + i));
	free(*grille);
}
