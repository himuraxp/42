/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 23:12:33 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/10 22:45:50 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_is_negative(int n)
{
	int number;

	number = n;
	if (number >= 0)
		ft_putchar('P');
	else
		ft_putchar('N');
	ft_putchar('\n');
}
