/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 19:23:34 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/21 19:43:31 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int));
int	ft_sort(int a, int b)
{
	return (a - b);
}

int	main(void)
{
	int tab[] = {1,2,3,4,6,6,7};
	int (*f)(int, int);

	f = &ft_sort;
	printf("%d\n", ft_is_sort(tab, 7, f));
		return (0);
}
