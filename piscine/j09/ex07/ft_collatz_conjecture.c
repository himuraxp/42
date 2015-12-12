/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 07:20:45 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/17 12:52:03 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base < 2)
		return (0);
	if (base % 2 == 0)
		base = base / 2;
	else
		base = base * 3 + 1;
	return (ft_collatz_conjecture(base) + 1);
}
