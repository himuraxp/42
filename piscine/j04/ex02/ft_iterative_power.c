/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 11:53:27 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/13 13:34:25 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int result;
	int i;

	i = 1;
	result = nb;
	if (nb >= 1 && power >= 1)
	{
		while (i < power)
		{
			result = result * nb;
			i++;
		}
		return (result);
	}
	else if (nb < 0 || power < 0)
	{
		return (0);
	}
	else
		return (0);
}
