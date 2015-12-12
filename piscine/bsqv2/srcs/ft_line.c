/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 21:12:16 by gmarguer          #+#    #+#             */
/*   Updated: 2015/07/30 23:07:06 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_modif_item(t_read *read, int i)
{
	read->empty = read->cpy[i - 3];
	read->used = read->cpy[i - 2];
	read->filling = read->cpy[i - 1];
	read->cpy[13] = '\0';
	read->line = ft_atoiv2(read->cpy);
	if (!(read->array = (char**)malloc((read->line + 3) * sizeof(char*))))
		return (ft_return_error(66, read));
	read->start = 1;
	return (1);
}

int		ft_first_line(t_read *read)
{
	int		i;

	i = 0;
	while (read->cpy[i] != '\0')
		i++;
	if (read->buf[0] != '\n')
	{
		if (i == 14)
			return (ft_return_error(12, read));
		read->cpy[i] = ft_dupchar(read->buf[0]);
		read->cpy[i + 1] = '\0';
	}
	else
		ft_modif_item(read, i);
	return (1);
}

int		ft_modif_item2(t_read *read)
{
	read->start = 2;
	if (!(ft_create_2d(read)))
		return (ft_return_error(16, read));
	if (!(ft_join(read, '\n')))
		return (ft_return_error(17, read));
	if (!(read->array[1] = ft_dup(read->array[1], read->str)))
		return (0);
	read->buf = ft_createmalloc(read->size + 2, read);
	read->buf_size = read->size + 1;
	return (1);
}

int		ft_second_line(t_read *read)
{
	if (read->buf[0] != '\n' && read->buf[0] != '\0' && read->size < 1000000000)
	{
		if (!(ft_join(read, read->buf[0])))
			return (ft_return_error(11, read));
		read->size += 1;
	}
	else
	{
		if (read->buf[0] == '\0')
			return (ft_return_error(13, read));
		else if (read->buf[0] == '\n')
		{
			if (ft_modif_item2(read) != 1)
				return (16);
		}
		else
			return (ft_return_error(15, read));
	}
	return (1);
}

int		ft_all(t_read *read)
{
	if (read->start > read->line)
		return (ft_return_error(21, read));
	read->array[read->start] = ft_dup(read->array[read->start], read->buf);
	if (read->array[read->start][read->size] != '\n')
		return (ft_return_error(18, read));
	if (read->start == read->line + 1)
	{
		if (read->array[read->start][0] != '\0')
			return (ft_return_error(19, read));
	}
	read->start += 1;
	return (1);
}
