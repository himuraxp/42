/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbase_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:14:31 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/12/23 16:15:31 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printbase_down(long int value, char base)
{
	if (base <= 36 && base >= 2 && value >= 0)
	{
		if (value >= base)
		{
			ft_printbase_down(value / base, base);
			ft_printbase_down(value % base, base);
		}
		else
		{
			if (value > 9)
				ft_putchar(value + 87);
			else
				ft_putchar(value + 48);
		}
	}
	else
		ft_putchar('0');
}
