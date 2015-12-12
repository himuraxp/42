/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 22:41:48 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/14 22:55:21 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	while ((i * i) <= nb && (i * i) > 0)
	{
		i++;
	}
	return (i);
}

int		ft_is_prime(int nb)
{
	int i;
	int sqrt;

	sqrt = ft_sqrt(nb);
	i = 3;
	if (nb % 2 == 0)
	{
		return (0);
	}
	while (i <= sqrt)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i = i + 2;
	}
	return (1);
}
