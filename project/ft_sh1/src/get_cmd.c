/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:35:25 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/03 00:41:42 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int     ft_strlen_c(char *str, char c, int pos)
{
    int i;
    int tmp;

    i = 0;
    if (pos == 0)
        while (str[i] != c)
            i++;
    else
    {
        while (str[i] != c)
            i++;
        tmp = i;
        while (str[tmp] != '\0')
            tmp++;
        i -= tmp;
    }
    return (i);
}

void    get_line_cmd(char *line)
{
    int     len_cmd;
    int     len_arg;
    char    *cmd;
    char    *arg;

    len_cmd = ft_strlen_c(line, ' ', 0);
    len_arg = ft_strlen_c(line, ' ', 1);
    cmd = ft_strnew(len_cmd);
    arg = ft_strnew(len_arg);
    ft_strncpy(cmd, line, len_cmd);
    ft_strncpy(arg, line, len_arg);
    ft_putstr(cmd);
    ft_putchar('\n');
    ft_putstr(arg);
    ft_putchar('\n');
}
