/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 13:55:14 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/30 14:49:06 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		ft_atoi(char *str)
{
	int result;
	int i;
	int sign;

	result = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (sign * result);
}

int		do_op(int nb1, char op, int nb2)
{
	int result;

	result = 0;
	if (op == '+')
		result = nb1 + nb2;
	if (op == '-')
		result = nb1 - nb2;
	if (op == '*')
		result = nb1 * nb2;
	if (op == '/')
		result = nb1 / nb2;
	if (op == '%')
		result = nb1 % nb2;
	return (result);
}

int		main(int argc, char **argv)
{
	int		nb1;
	int		nb2;
	char	*op;

	op = argv[2];
	if (argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	nb1 = ft_atoi(argv[1]);
	nb2 = ft_atoi(argv[3]);
	printf("%d\n", do_op(nb1, *op, nb2));
	return (0);
}
