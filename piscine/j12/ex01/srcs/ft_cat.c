/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 10:10:18 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/24 09:37:42 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_include.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	int		c;

	c = 1;
	while (c <= argc)
	{
		fd = open(argv[c], O_RDONLY);
		if (fd == -1)
			return (1);
		while ((ret = read(fd, buf, BUF_SIZE)))
		{
			buf[ret] = '\0';
			ft_putstr(buf);
		}
		buf[ret] = '\0';
		ft_putstr(buf);
		if (close(fd) == -1)
			return (1);
		c++;
	}
	return (0);
}
