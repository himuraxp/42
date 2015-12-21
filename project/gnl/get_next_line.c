/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 11:13:38 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/21 15:57:41 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_read(int const fd, int *ret)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		eof;

	ft_bzero(buf, BUFF_SIZE + 1);
	tmp = ft_strnew(BUFF_SIZE);
	while (!ft_strchr(buf, '\n'))
	{
		eof = read(fd, buf, BUFF_SIZE);
		if (eof < 0)
			return (NULL);
		if (!eof)
		{
			*ret = 1;
			return (tmp);
		}
		buf[eof] = '\0';
		tmp = ft_strjoin(tmp, buf);
		ft_strdel((char **)&buf);
	}
	return (tmp);
}

static char		*ft_remove_eof(char *buf, char **tmp, char *next)
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

static int		ft_return(char **line, int ret)
{
	if (!line || !*line)
		return (-1);
	else if (ret)
		return (0);
	else
		return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char		buf[BUFF_SIZE + 1];
	char			*tmp;
	char			*next;
	int				ret;

	ret = 0;
	tmp = NULL;
	if (fd < 0 || !line)
		return (-1);
	if (!(next = ft_strchr(buf, '\n')))
	{
		if (!(tmp = ft_read(fd, &ret)))
			return (-1);
		next = ft_strchr(tmp, '\n');
	}
	if (next)
		*next = '\0';
	*line = ft_remove_eof(buf, &tmp, next);
	return (ft_return(line, ret));
}
