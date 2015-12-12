/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 20:53:45 by mfroehly          #+#    #+#             */
/*   Updated: 2015/07/21 10:56:19 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grille.h"
#include "error.h"
#include "resolution.h"

int		main(int argc, char *argv[])
{
	char	**grille;
	char	valeur;
	int		x;
	int 	y;

	x = 0;
	y = 0;
	if (error(argc, argv))
		return (1);
	if (!init_grille(argv, &grille))
	{
		print_error();
		return (1);
	}
	print_grille(grille);
	free_grille(&grille);
	return (0);
}
