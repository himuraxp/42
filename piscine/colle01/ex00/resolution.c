/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 05:11:39 by mfroehly          #+#    #+#             */
/*   Updated: 2015/07/19 18:41:36 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	at_coor(int *coor, char **grille, int j, int i)
{
	return (*(*(grille + ((coor[1] / 3) * 3) + j) + ((coor[0] / 3) * 3) + i));
}

int		is_dispo_block(char valeur, int *coor, char **grille)
{
	int		i;
	int		j;
	char	temp;

	i = -1;
	j = -1;
	while (++i < 3)
	{
		while (++j < 3)
			if (!(i == coor[0] % 3 && j == coor[1] % 3))
				if (valeur == at_coor(coor, grille, j, i))
					return (0);
		j = -1;
	}
	return (1);
}

int		is_dispo(char valeur, int *coor, char **grille)
{
	int i;

	i = -1;
	if (*(*(grille + coor[1]) + coor[0]) != '.')
		return (0);
	while (++i < 9)
		if (i != coor[1])
			if (valeur == *(*(grille + i) + coor[0]))
				return (0);
	i = -1;
	while (++i < 9)
		if (i != coor[0])
			if (valeur == *(*(grille + coor[1]) + i))
				return (0);
	return (is_dispo_block(valeur, coor, grille));
}

char	one_solution(int *coor, char **grille)
{
	char	i;
	int		temoin;
	int		one_solution;
	char	temp;

	i = '0';
	temoin = 0;
	one_solution = 1;
	while (++i <= '9')
	{
		temoin += is_dispo(i, coor, grille);
		if (is_dispo(i, coor, grille))
			temp = i;
	}
	return (temoin == 1 ? temp : '0');
}

void	pre_remplissage(char **grille)
{
	int		coor[2];
	int		temoin;
	char	temp;

	coor[0] = -1;
	coor[1] = -1;
	temoin = 1;
	while (temoin)
	{
		temoin = 0;
		while (++coor[0] < 9)
		{
			while (++coor[1] < 9)
			{
				temp = one_solution(coor, grille);
				if (temp != '0')
				{
					*(*(grille + coor[1]) + coor[0]) = temp;
					temoin = 1;
				}
			}
			coor[1] = -1;
		}
		coor[0] = -1;
	}
}
