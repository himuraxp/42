/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 12:42:05 by ylarbi            #+#    #+#             */
/*   Updated: 2016/05/31 11:11:42 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(const char *str)
{
	int	result;

	result = 0;
	while (str++ != '\0')
		result++;
	return (result);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *str)
{
	char	*new;

	if (!(new = (char *)malloc(sizeof(*str) * (ft_strlen(str) + 1))))
		return (NULL);
	ft_strcpy(new, str);
	return (new);
}

int				ft_len(int n)
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

static char		*ft_solve(char *str, int len, int n)
{
	while (n > 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	sign = 0;
	if (n == -2147483648)
			return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		sign = 1;
		len = ft_len(n) + 1;
	}
	else
		len = ft_len(n);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[len--] = '\0';
	str = ft_solve(str, len, n);
	if (sign == 1)
		str[0] = '-';
	return (str);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
