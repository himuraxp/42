/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 00:31:37 by gmarguer          #+#    #+#             */
/*   Updated: 2015/07/30 23:25:18 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			ft_len(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

char		*ft_dup(char *dest, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		ft_dupchar(char c)
{
	char	temp;

	temp = c;
	return (temp);
}

void		ft_putkebab(t_read *read)
{
	int		y;
	int		x;

	y = 1;
	x = 0;
	while (y <= read->line)
	{
		write(1, read->array[y], read->size + 1);
		y++;
	}
}

int			ft_handling(t_read *read)
{
	if (read->start <= read->line)
		return (0);
	if (!(ft_seek(read)))
		return (0);
	ft_putkebab(read);
	return (1);
}
