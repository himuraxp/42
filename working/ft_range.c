/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:51:43 by ylarbi            #+#    #+#             */
/*   Updated: 2016/05/12 15:56:12 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*(str) != '\0')
		ft_putchar(*(str++));
}

void	ft_putnbr(int n)
{
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

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
					|| str[i] == '\f' || str[i] == '\r')
				return (sign * result);
		i++;
	}
	return (sign * result);
}

int		*ft_range(int start, int end)
{
	int	*tab;
	int len;
	int i;

	i = 0;
	tab = NULL;
	len = 0;
	if (start > end)
	{
		if (end < 0)
			len = start + (-end);
		else
			len = start - end;
	}
	else if (end > start)
	{
		if (start < 0)
			len = end + (-start);
		else
			len = end - start;
	}
	if (!(tab = (int *)malloc(sizeof(*tab) * len)))
		return (NULL);
	else
	{
		while (i <= len)
		{
			if (start < end)
			{
				if (start < 0)
					tab[i] = start + i;
				else if (start == 0 || tab[i] == -1)
					tab[i] = start;
				else if (start > 0)
					tab[i] = start + i;
			}
			else
			{
				if (end < 0)
					tab[i] = start - i;
				else if (start == 0 || tab[i] == -1)
					tab[i] = start;
				else if (end > 0)
					tab[i] = start - i;
			}
			i++;
		}
		tab[i] = '\0';
	}
	return (tab);
}

int		main(int ac, char **av)
{
	int *tab;
	int i;
	int start;
	int end;

	start = 0;
	end = 0;
	i = 0;
	tab = NULL;
	if (ac == 3)
	{
		start = ft_atoi(av[1]);
		end = ft_atoi(av[2]);
		tab = ft_range(start, end);
		while (tab[i])
		{
			ft_putnbr(tab[i]);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}

