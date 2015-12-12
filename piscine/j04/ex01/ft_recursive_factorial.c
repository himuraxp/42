/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 11:09:31 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/13 14:11:05 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int result;
	int i;

	i = 1;
	result = nb;
	if (nb > 0 && nb < 13)
	{
		i++;
		nb--;
		result = result * ft_recursive_factorial(nb);
		return (result);
	}
	else if (nb == 0)
		return (1);
	else
		return (0);
}
