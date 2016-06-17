/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:51:43 by ylarbi            #+#    #+#             */
/*   Updated: 2016/05/10 16:34:27 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while(*(str))
		ft_putchar(*(str++));
}

int		ft_atoi(char *str)
{
	int	i;
	int	sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		ft_putchar('-');
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' || str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
		}
		i++;
	}
	return (sign * result);
}

void	ft_putnbr(int n)
{
	int convert;

	convert = 0;
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}

void	tab_mult(int tab)
{
	int i;

	i = 1;
	while (i < 10)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		ft_putnbr(tab);
		ft_putstr(" = ");
		ft_putnbr(tab * i);
		ft_putchar('\n');
		i++;
	}
}


int		main(int ac, char **av)
{
	int convert;

	convert = 0;
	if (ac != 2)
		ft_putchar('\n');
	else
	{
		convert = ft_atoi(av[1]);
		tab_mult(convert);
	}
	return (0);
}
