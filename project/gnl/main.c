/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:14:11 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/21 15:54:22 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int fd;
	char *str;

	fd = open(av[1], O_RDONLY);
	if (ac != 2 || fd < 0)
		return (0);
	get_next_line(fd, &str);
	ft_putstr(str);
	return (0);
}
