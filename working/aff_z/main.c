/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 18:21:49 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/23 18:31:28 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	aff_z(char *str);

int		main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	aff_z(av[1]);
	return (0);
}