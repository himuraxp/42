/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:17:03 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/18 12:30:03 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int	result;
	int i;
	int sign;

	result = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}
