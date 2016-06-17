/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 12:43:32 by ylarbi            #+#    #+#             */
/*   Updated: 2016/06/14 11:16:21 by ylarbi           ###   ########.fr       */
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
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
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
		ft_putnbr(n % 10);
		ft_putchar((n / 10) + '0');
	}
	else
		ft_putchar(n + '0');
}

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int result;

	result = 0;
	sign = 1;
	i = 0;
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
		else
			return(result * sign);
		i++;
	}
	return(result * sign);
}

int		ft_len(int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char *str;
	int	sign;
	int	len;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
		len = ft_len(-n) + 1;
	}
	else
		len = ft_len(n);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (n > 0)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

int		main(int ac, char **av)
{
	int convert;

	convert = 0;
	if (ac == 2)
	{
		convert = ft_atoi(av[1]);
		ft_putstr(ft_itoa(convert));
	}
	return (0);
}
