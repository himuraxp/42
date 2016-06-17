/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 18:48:26 by ylarbi            #+#    #+#             */
/*   Updated: 2016/05/10 14:42:12 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base(const char *str, int str_base)
{
	int i;
	int result;
	int sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str_base <= 16)
	{
		if (str[i] == '-')
			sign = -1;
		while (str[i] != '\0')
		{
			if ((str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <=
			'F'))
				result += str[i] % 10 + '0';
			i++;
		}
		return (sign * result);
	}
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_atoi_base()
	}
	return (0);
}
