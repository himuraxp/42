/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:36:39 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/14 21:06:30 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fix_node(t_data *data, t_node *pos)
{
	t_node *curs;

	if (!data->map)
	{
		data->map = pos;
		data->count = data->map;
	}
	else
	{
		if (data->o <= data->xmap)
		{
			curs = end(data->count);
			curs->right = pos;
		}
		else
		{
			(data->count)->down = pos;
			data->count = (data->count)->down;
			data->o = 1;
		}
	}
}

t_node		*new_node(t_data *data, t_point *new)
{
	t_node	*pos;

	if(!(pos = malloc(sizeof(t_node))))
		exit(-1);
	pos->right = NULL;
	pos->down = NULL;
	pos->point = new;
	fix_node(data, pos);
	if(!data->map)
		return (pos);
	return (data->map);
}

t_node		*grid_line(t_data *data, char *line, int nbr_line)
{
	char	**nbr;
	int		x;

	x = -1;
	nbr = ft_strsplit(line, ' ');
	while(nbr[++x])
	{
		data->o += 1;
		new_node(data, new_point(x, nbr_line, ft_atoi(nbr[x])));
	}
	return (0);
}

int			get_nbr_line(char *str)
{
	int		nbr_char;
	int		i;

	i = -1;
	nbr_char = 1;
	while(str[++i] && str[i] != '\n')
		if (str[i] == ' ')
			nbr_char++;
	return (nbr_char);
}

int			get_next_map(t_data *data, char *map)
{
	char	*line;
	int		fd;
	int		nbr_line;

	fd = open(map, O_RDONLY);
	nbr_line = 1;
	data->o = 0;
	get_next_line(fd, &line);
	data->xmap = get_nbr_line(line);
	data->map = 0;
	grid_line(data, line, nbr_line);
	close(fd);
	return (0);
}
