/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 21:30:18 by gmarguer          #+#    #+#             */
/*   Updated: 2015/07/30 22:51:01 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_join(t_read *read, char c)
{
	int		i;

	i = 0;
	read->temp = read->str;
	if (!(read->str = ft_createmalloc(ft_len(read->str) + 2, read)))
		return (0);
	while (read->temp[i] != '\0')
	{
		read->str[i] = read->temp[i];
		i++;
	}
	read->str[i] = c;
	read->str[i + 1] = '\0';
	free(read->temp);
	return (1);
}

int		ft_read(int o, t_read *rd)
{
	while ((rd->r = read(o, rd->buf, rd->buf_size)))
	{
		rd->buf[rd->buf_size] = '\0';
		if (rd->r == -1 || rd->error != 0)
			return (0);
		else if (rd->start == 0)
			ft_first_line(rd);
		else if (rd->start == 1)
			ft_second_line(rd);
		else
			ft_all(rd);
		if (rd->error != 0)
			return (0);
	}
	return (1);
}

int		ft_open(char *file, t_read *read)
{
	int		o;

	if ((o = open(file, O_RDONLY, S_IREAD)))
	{
		if (o == -1)
		{
			return (0);
		}
		return (ft_read(o, read));
	}
	close(o);
	return (1);
}

void	ft_error(t_read *read)
{
	(void)read;
	write(2, "map error\n", 10);
	ft_free(read);
	return ;
}

void	ft_bsq(char *file, int param)
{
	t_read	*read;

	read = ft_create_r();
	if (param == 1)
	{
		if (!(ft_open(file, read)))
			return (ft_error(read));
	}
	else
	{
		if (!(ft_read(0, read)))
			return (ft_error(read));
	}
	if (!(ft_handling(read)))
		return (ft_error(read));
}
