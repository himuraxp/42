/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 22:27:48 by ylarbi            #+#    #+#             */
/*   Updated: 2016/05/08 00:42:32 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar(nb + '0');
}

int		ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			break;
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

void	add_prime_sum(int prime)
{
	int	i;

	i = 5;
	if (prime == 1 || prime == 2 || prime == 3 || prime == 5)
		ft_putnbr(prime);
	if (prime % 2 == 0 || prime % 3 == 0)
		ft_putnbr(0);
	while (i <= prime)
	{
		if (prime % i == 0)
			exit(0);
		else
			i += 2;
		ft_putnbr(i);
	}
}

int main(int argc, char **argv)
{
	int result;

	result = 0;
	if (argc == 2)
	{
		result = ft_atoi(argv[1]);
		add_prime_sum(result);
	}
	else
		ft_putchar('0');
	return (0);
}
