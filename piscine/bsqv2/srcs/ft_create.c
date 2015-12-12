/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 20:35:00 by gmarguer          #+#    #+#             */
/*   Updated: 2015/07/30 23:01:39 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_seek		*ft_create_elem(t_read *read)
{
	t_seek	*seek;

	if (!(seek = malloc(sizeof(t_seek))))
		return (0);
	seek->size = -1;
	seek->ymax = read->line;
	seek->xmax = read->size;
	seek->ymin = 1;
	seek->xmin = 0;
	seek->savey = 0;
	seek->savex = 0;
	seek->empty = read->empty;
	seek->used = read->used;
	seek->x = 0;
	seek->y = 0;
	seek->filling = read->filling;
	seek->nextx = 0;
	seek->tempy = 0;
	seek->tempx = 0;
	return (seek);
}

t_count		*ft_create_i(int value)
{
	t_count	*i;

	if (!(i = malloc(sizeof(t_count))))
		return (0);
	i->x = value;
	i->y = value;
	i->col = value;
	i->start = value;
	return (i);
}

t_read		*ft_create_r(void)
{
	t_read	*read;

	if (!(read = malloc(sizeof(t_read))))
		return (0);
	if (!(read->buf = malloc(sizeof(char) * 2)))
		return (0);
	if (!(read->str = malloc(sizeof(char) * 3)))
		return (0);
	read->str[0] = '\0';
	read->array = 0;
	read->size = 0;
	read->cpy[0] = '\0';
	read->buf_size = 1;
	read->start = 0;
	read->r = 0;
	read->line = 0;
	read->error = 0;
	return (read);
}

int			ft_create_2d(t_read *read)
{
	int		i;

	i = 1;
	while (i <= read->line)
	{
		if (!(read->array[i] = ft_createmalloc(read->size + 2, read)))
			return (ft_return_error(17, read));
		i++;
	}
	return (1);
}

char		*ft_createmalloc(int size, t_read *read)
{
	char	*temp;

	temp = malloc((size + 1) * sizeof(char*));
	if (temp == NULL)
		read->error = 100;
	return (temp);
}
