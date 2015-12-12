/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 10:10:18 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/23 15:28:46 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_include.h"

int		ft_error(int argc)
{
	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	else
		return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (ft_error(argc) == 0)
	{
		fd = open(argv[1], O_RDONLY);
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
	}
	return (0);
}
