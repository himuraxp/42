/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:30:40 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/04 11:46:53 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char        **g_env;
char        *g_path;
static char *g_login;

int     ft_envnbr(char **env)
{
    int i;

    i = 0;
    while (env[i])
        i++;
    return (i);
}

void	ft_envcpy(char **src, char **dst)
{
	int		i;

	i = -1;
	while (src[++i])
		dst[i] = ft_strdup(src[i]);
	dst[i] = NULL;
}

char	**get_param(void)
{
    char	**arg;
    char	*line;
	char	tab;
    int		i;

	if ((get_next_line(0, &line)) == 2)
        ft_putstr("Salut");
	if (line)
	{
		i = -1;
		while (line[++i] != '\0')
		{
			tab = line[i];
			if (tab == '\t')
				line[i] = ' ';
		}
		arg = ft_strsplit(line, ' ');
		return (arg);
	}
	return (NULL);
}

int		main(int ac, char **av, char **env)
{
	char		**arg;
    char		*cmd;
	int			line;
    int         o_path;


    cmd = NULL;
    o_path = 0;
    if (ac == 2)
        if (ft_strcmp(av[1], "-p") == 0)
            o_path = 1;
	line = ft_envnbr(env);
	g_env = malloc(sizeof(char *) * 2048);
    g_path = malloc(sizeof(char) * 2048);
	ft_envcpy(env, g_env);
    while (1)
	{
        if (o_path == 1)
            prompt_path(g_path, g_env);
		else
        {
            g_login = get_user(g_env);
            prompt(g_login);
        }
        //check_sign();
		arg = get_param();
		process(cmd, arg, g_env);
	}
	return (0);
}
