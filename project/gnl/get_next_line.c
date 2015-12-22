/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 21:53:51 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/22 01:49:10 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_read(int fd, int *stop)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		eof;

	ft_bzero(buf, BUFF_SIZE + 1);
	tmp = ft_strnew(BUFF_SIZE);
	while (!(ft_strchr(buf, '\n')))
	{
		eof = read(fd, buf, BUFF_SIZE);
		if (eof < 0)
			return (NULL);
		if (!eof)
		{
			*stop = 1;
			return (tmp);
		}
		buf[eof] = '\0';
		tmp = ft_strjoin(tmp, buf);
		ft_strdel((char**)&buf);
	}
	return (tmp);
}

static char		*ft_eof(char *buf, char **tmp, char *next)
{
	char	*line;

	line = ft_strjoin(buf, *tmp);
	if (next)
		ft_strcpy(buf, next + 1);
	else
		ft_bzero(buf, BUFF_SIZE + 1);
	if (*tmp)
		ft_strdel(tmp);
	return (line);
}

static int		ft_return(char **line, int stop)
{
	if (!line || !*line)
		return (-1);
	else if (stop)
		return (0);
	else
		return (1);
}

int		get_next_line(int const fd, char **line)
{
	static char	buf[BUFF_SIZE + 1];
	char		*next;
	char		*tmp;
	int			stop;

	stop = 0;
	ft_putstr("get_next_line start\n");
	if (fd < 0 || !line)
		return (-1);
	if (!(next = ft_strchr(buf, '\n')))
	{
		ft_putstr("if next = ft_strchr\n");
		if (!(tmp = ft_read(fd, &stop)))
		{
			ft_putstr("if tmp = ft_read\n");
			return (-1);
		}
		next = ft_strchr(tmp, '\n');
	}
	if (!(next == NULL))
	{
		ft_putstr("if next existe\n");
		*next = '\0';
	}
	*line = ft_eof(buf, &tmp, next);
	return (ft_return(line, stop));
}
