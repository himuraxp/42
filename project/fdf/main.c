/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 22:49:51 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/13 11:18:45 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/fdf.h"

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		gnl;

	gnl = 0;
	if (ac < 2)
		return (0);
	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		fd = 0;
	gnl = get_next_line(fd, &line);
	while (gnl != 0 && gnl != -1)
	{
		ft_fdf(av[1]);
		gnl = get_next_line(fd, &line);
	}
	if (gnl == -1)
		ft_putstr("Error reading file.\n");
	if	(fd != 0)
		close(fd);
	return (0);
}
