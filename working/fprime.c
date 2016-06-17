/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 10:49:31 by ylarbi            #+#    #+#             */
/*   Updated: 2016/05/30 12:03:36 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_isprime(int n)
{
	int i;

	if (n <= 1)
		return (0);
	i = 2;
	while (n % i != 0)
		i++;
	return (i);
}

void	fprime(int n)
{
	int	diviser;

	diviser = ft_isprime(n);
	if (diviser == n)
		printf("%d", n);
	else if (diviser != 0)
	{
		fprime(diviser);
		printf("*");
		fprime(n / diviser);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
