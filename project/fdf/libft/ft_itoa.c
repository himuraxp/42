/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:05:57 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/06 19:14:12 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int result;

	result = 0;
	if (n == 0)
		return (result + 1);
	while (n > 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static char	*ft_solve(char *str, int count, int n)
{
	while (n > 0)
	{
		str[count--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		sign;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		count = ft_len(n) + 1;
		sign = 1;
	}
	else
		count = ft_len(n);
	if ((str = (char *)malloc(sizeof(*str) * (count + 1))) == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[count--] = '\0';
	str = ft_solve(str, count, n);
	if (sign == 1)
		str[0] = '-';
	return (str);
}
