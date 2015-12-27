/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:14:11 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/27 17:18:39 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
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
		ft_putstr(line);
		write(1, "\n", 1);
		gnl = get_next_line(fd, &line);
	}
	if (gnl == -1)
		ft_putstr("Error reading file.\n");
	if (fd != 0)
		close (fd);
	return (0);
}
