/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:30:40 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/01 10:35:15 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void    prompt(void)
{
    char    *buf;
    char    **line;

    line = NULL;
    ft_putstr("\n$> ");
    get_next_line(fgetc(stdin), line);
}

void     ft_sh1(char **av)
{
    pid_t   father;
    char    *fd;

    fd = NULL;
    father = fork();
    if (father > 0)
        prompt();
    if (father == 0)
        ft_putstr("Minishel\n");
}

int     main(int ac, char **av)
{
    if (ac == 1)
    {
        ft_sh1(av);

    }
    return (0);
}
