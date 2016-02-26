/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:36:39 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/19 20:04:43 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fix_node(t_data *data, t_node *pos)
{
	t_node *curs;

	ft_putstr("fix_node start\n");
	if (!data->map)
	{
		data->map = pos;
		data->count = data->map;
	}
	else
	{
		if (data->o <= data->xmap)
		{
			ft_putstr("fix_node -> end\n");
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
	ft_putstr("fix_node end\n");
}

t_node		*new_node(t_data *data, t_point *new)
{
	t_node	*pos;

	ft_putstr("new_node start\n");
	if(!(pos = malloc(sizeof(t_node))))
		exit(-1);
	pos->right = NULL;
	pos->down = NULL;
	pos->point = new;
	ft_putstr("new_node -> fix_node\n");
	fix_node(data, pos);
	if(!data->map)
		return (pos);
	ft_putstr("new_node end\n");
	return (data->map);
}

t_node		*grid_line(t_data *data, char *line, int nbr_line)
{
	char	**nbr;
	int		x;

	x = -1;
	ft_putstr("grid_line start\n");
	ft_putstr("grid_line -> ft_strsplit\n");
	nbr = ft_strsplit(line, ' ');
	while(nbr[++x])
	{
		data->o += 1;
		new_node(data, new_point(x, nbr_line, ft_atoi(nbr[x])));
	}
	ft_putstr("grid_line end\n");
	return (0);
}

int			get_nbr_line(char *str)
{
	int		nbr_char;
	int		i;

	i = -1;
	nbr_char = 1;
	ft_putstr("get_nbr_line start\n");
	while(str[++i] && str[i] != '\n')
		if (str[i] == ' ')
			nbr_char++;
	ft_putstr("get_nbr_line end\n");
	return (nbr_char);
}

int			get_next_map(t_data *data, char *map)
{
	char	*line;
	int		fd;
	int		nbr_line;

	ft_putstr("get_next_map start\n");
	ft_putstr("get_next_map -> open\n");
	fd = open(map, O_RDONLY);
	nbr_line = 1;
	data->o = 0;
	ft_putstr("get_next_map -> get_next_line\n");
	get_next_line(fd, &line);
	ft_putstr("get_next_map -> get_nbr_line\n");
	data->xmap = get_nbr_line(line);
	data->map = 0;
	ft_putstr("get_next_map -> grid_line\n");
	grid_line(data, line, nbr_line);
	ft_putstr("get_next_map -> close\n");
	close(fd);
	ft_putstr("get_next_map end\n");
	return (0);
}
