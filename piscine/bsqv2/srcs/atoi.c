/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 14:39:52 by gmarguer          #+#    #+#             */
/*   Updated: 2015/07/30 16:34:18 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_atoiv2(char *str)
{
	int		output;
	int		i;

	i = 0;
	output = 0;
	while (str[i + 3] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			output = output * 10 + str[i] - '0';
		else
			return (0);
		i++;
	}
	return (output);
}
