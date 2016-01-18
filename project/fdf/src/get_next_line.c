/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 18:38:19 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/17 16:47:19 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int		cut(char *str_chr, char *save)
{
	save[0] = 0;
	if (!str_chr)
		return (0);
	*str_chr = '\0';
	str_chr++;
	ft_strcpy(save, str_chr);
	ft_memset(str_chr, 0, ft_strlen(str_chr));
	return (1);
}

static char		*strjoin_free(char **line, char *buf)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, buf);
	free(tmp);
	tmp = NULL;
	return (*line);
}

int				get_next_line(int const fd, char **line)
{
	int				ret;
	char			*str_chr;
	char			buf[BUFF_SIZE + 1];
	static char		save[4096][BUFF_SIZE];

	if (!line || fd < 0)
		return (-1);
	if (!(*line = *save[fd] ? ft_strdup(save[fd]) : ft_strnew(1)))
		return (-1);
	buf[0] = 0;
	while (((str_chr = ft_strchr(*line, '\n')) == NULL)
			&& ((ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		if (!(*line = strjoin_free(line, buf)))
			return (-1);
	}
	if (cut(str_chr, save[fd]) == 1 || ft_strlen(*line) || ret > 0)
		return (1);
	return (ret == 0 ? 0 : -1);
}
