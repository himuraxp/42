/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrambler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 07:51:12 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/17 12:55:23 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int tmp;

	tmp = ***a;
	***a = *b;
	*b = ****d;
	****d = *******c;
	*******c = tmp;
}
