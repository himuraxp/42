/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 14:46:11 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/30 14:52:01 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_atoi(char *str);

int		main(int argc, char **argv)
{
	int nb;

	if (argc != 2)
		return (0);
	nb = ft_atoi(argv[1]);
	printf("%d", nb);
	return (0);
}