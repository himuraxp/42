/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 18:28:52 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/21 22:17:42 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int temp;
	int count;

	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	while (nb > 9)
	{
		temp = nb;
		count = 1;
		while (temp > 9)
		{
			temp /= 10;
			count *= 10;
		}
		ft_putchar((char)(temp + '0'));
		nb %= count;
	}
	ft_putchar((char)(nb + '0'));
}

void	ft_show_tab(struct s_stock_par *par)
{
	int i;

	while (par->str)
	{
		ft_putstr(par->copy);
		ft_putstr("\n");
		ft_putnbr(par->size_param);
		i = 0;
		while ((par->tab)[i])
		{
			ft_putstr("\n");
			ft_putstr((par->tab)[i++]);
		}
		ft_putstr("\n");
		par++;
	}
}
