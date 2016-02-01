/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:30:40 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/01 13:34:58 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void    prompt(void)
{
    static int   start;

    if (start != 0)
       ft_str_color("$> ", "cyan", "bold");
    if (start == 0)
    {
        ft_str_color("\n$> ", "cyan", "bold");
        start = 1;
    }
}



void     ft_sh1(void)
{
    char    *line;
    char    *arg;
    int     len;
    pid_t   father;

    father = fork();
    while (father > 0)
    {
        prompt();
        if (!(get_next_line(0, &line)))
        {
            ft_str_color("exit", "red", 0);
            exit(0);
        }
        if (strcmp(line, "ls -l") == 0)
        {

            arg = ft_strnew(2);
            len = ft_strlen(line);
            ft_putnbr(len);
            arg[0] = line[len - 2];
            arg[1] = line[len - 1];
            ft_putstr(arg);
            execve("/bin/ls", &arg, NULL);
        }
        if (strcmp(line, "exit") == 0)
            exit(0);
//            get_cmd(line);
    }
}

int     main(void)
{
    ft_sh1();
    return (0);
}
