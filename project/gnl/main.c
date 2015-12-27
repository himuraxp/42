/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:14:11 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/27 14:02:04 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char *str;
	int fd;

	fd = open("txt", O_RDONLY);
	while (fd)
	{
		get_next_line(fd, &str);
		ft_putstr(str);
		write(1, "\n", 1);
		free(str);
	}
	return (0);
}
