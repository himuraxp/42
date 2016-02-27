/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:31:31 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/26 23:22:10 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_strcount(char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
        if ((!ft_isdigit(s[i]) && s[i] != '-' && s[i] != ' ')
            || (s[i] == '-' && !ft_isdigit(s[i + 1]))
            || (i > 0 && s[i] == '-' && s[i - 1] != ' '))
            error_param("isdigit :'(", 1);
		if (j == 0 && s[i] != c)
		{
			j = 1;
			k++;
		}
		if (s[i] == c)
			j = 0;
		i++;
	}
	return (k);
}

void    verif_valid(char *map)
{
    int     fd;
    int     i;
    char	buf[2];
    int     ret;

    i = -1;
    ft_putstr("init -> verif_valid\n");
    if (!(fd = open(map, O_RDONLY)))
    {
        error_param("Map non valide", 1);
        exit(1);
    }
    buf[1] = 0;
    while (++i < 50 && (ret = read(fd, buf, 1)) > 0)
        if (!ft_isprint(buf[0]) && buf[0] != 0 && buf[0] != '\n')
        {
            ft_putchar(buf[0]);
            error_param("Caracteres non valides", 1);
        }
    if (ret == -1)
        error_param("Impossible d'ouvrir le fichier en parametre", 1);
    close(fd);
}

void    check_len(t_data *data, char* map)
{
    int     fd;
    char    *line;
    int     result;

    data->y = 0;
    data->x = 0;
    ft_putstr("init -> check_len\n");
    if (!(fd = open(map, O_RDONLY)))
    {
        error_param("fd -> check_len on ouvert !", 1);
        exit(1);
    }
    while (get_next_line(fd, &line) == 1)
    {
        result = ft_strcount(line, ' ');
        if (data->x < result)
            data->x = result;
        data->y++;
    }
    close(fd);
    free(line);
    if (data->x == 0)
        error_param("Map invalide", 1);
}
