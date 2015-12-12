/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 09:57:15 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/13 14:03:49 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_interative_factorial(int nb)
{
	int result;
	int i;

	i = 1;
	result = nb;
	if (nb > 0 && nb < 13)
	{
		while (i <= nb)
		{
			result = result * (nb - 1);
			nb--;
			i++;
		}
		return (result);
	}
	else if (nb == 0)
		return (1);
	else
		return (0);
}
