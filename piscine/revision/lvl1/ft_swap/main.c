/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 16:32:19 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/29 17:09:54 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_swap(int *a, int *b);
int		ft_atoi(char *str);

int		main(int argc, char **argv)
{
	int a;
	int b;

	a = ft_atoi(argv[1]);
	b = atoi(argv[2]);
	if (argc != 3)
		return (0);

	printf("nb1 : %d\nnb2 : %d\n", a, b);
	ft_swap(&a, &b);
	printf("nb1 : %d\nnb2 : %d\n", a, b);
}
