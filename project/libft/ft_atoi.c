/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:04:10 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/06 19:01:47 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int	result;
	int	count;
	int	sign;

	sign = 1;
	count = 0;
	result = 0;
	while (ft_isblank(str[count]))
		count++;
	if (str[count] == '-')
	{
		sign = -1;
		count++;
	}
	else if (str[count] == '+')
		count++;
	while (ft_isdigit(str[count]) == 1)
	{
		if (str[count] >= '0' && str[count] <= '9')
			result = result * 10 + (str[count] - '0');
		else if (str[count++] == ' ')
			return (result * sign);
		count++;
	}
	return (result * sign);
}
