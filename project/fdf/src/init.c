/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 10:56:56 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/26 23:08:41 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_atoi_i(const char *str, int *i)
{
	int		output;
	int		sign;

	output = 0;
	sign = 0;
	while (str[*i] == ' ')
		*i += 1;
	while (str[*i])
	{
		if (str[*i] >= '0' && str[*i] <= '9')
			output = output * 10 + str[*i] - '0';
		if (str[*i] >= '0' && str[*i] <= '9')
			sign = sign ? sign : 1;
		else if (str[*i] == '-' && !sign)
			sign = -1;
		else if (str[*i] == '+' && !sign)
			sign = 1;
		else if (output || sign || (str[*i] < '0' || str[*i] > '9'))
			break ;
		*i += 1;
	}
	return (output * sign);
}

void    insert_map(t_data *data, int fd, int y, int x)
{
    char    *line;
    int     gnl;
    int     i;

    gnl = 0;
    while (++y < data->y)
    {
        if ((gnl = get_next_line(fd, &line)) == -1)
            error_param("gnl -1 !", 1);
            i = 0;
            while (++x < data->x)
			{
                data->map[y * data->x + x][0] = ft_atoi_i(line, &i);
				data->map[y * data->x + x][1] = x;
				data->map[y * data->x + x][2] = y;
			}
            x = -1;
        free(line);
    }
    y = -1;
    /*while (++y < data->nb_p)
    {
                ft_putnbr(data->map[y][0]);
                ft_putchar(' ');
				if (y % data->x == 0)
            		ft_putchar('\n');
    }
	ft_putchar('\n');*/
}

void get_next_map(t_data *data)
{
    int     result;
    int     i;


    result = 0;
    i = -1;
	data->nb_p = data->y * data->x;
    ft_putstr("init -> get_next_map\n");
    if (!(data->map = (int**)malloc(sizeof(int*) * data->nb_p)))
        return ;
    while (++i < data->nb_p)
    {
        if (!(data->map[i] = (int*)malloc(sizeof(int) * 3)))
            error_param("Error malloc get_next_map", 1);
    }
}

void	init(t_data *data, char *map)
{
    int fd;

    fd = 0;
	data->mlx = mlx_init();
	data->width = WIDTH;
	data->height = HEIGHT;
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
	ft_putstr("init -> get_next_map\n");
    verif_valid(map);
    check_len(data, map);
	get_next_map(data);
    fd = open(map, O_RDONLY);
    insert_map(data, fd, -1, -1);
    close(fd);
}
