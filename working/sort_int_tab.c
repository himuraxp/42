/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 12:43:32 by ylarbi            #+#    #+#             */
/*   Updated: 2016/06/07 14:13:25 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				tmp;
	int				action;

	i = -1;
	action = 0;
	while (++i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			action = 1;
		}
			printf("%d\n", tab[i]);
	}
	if (action == 1)
		sort_int_tab(tab, size);
}

int		main(int ac, char **av)
{
	int tab[5];

	ac = 0;
	av = NULL;
	tab[0] = 123;
	tab[1] = 65;
	tab[2] = 0;
	tab[3] = -955564;
	tab[4] = 65;

	sort_int_tab(tab, 5);
	return (0);
}
