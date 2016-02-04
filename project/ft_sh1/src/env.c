/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:55:50 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/03 17:33:16 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	del_env(char **arg, char **env)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = env;
	if (arg[0][1] == 'i')
	{
		while (tmp[++i])
		{
			env[i] = ft_strdup("EMPTY");
		}
		init_env(g_env);
	}
}

char	*exec_env(char **arg, char **g_env)
{
	char	*cmd;

	cmd = get_cmd(arg[0], g_env);
	if (cmd != NULL)
	{
		return (cmd);
	}
	return (NULL);
}

void	print_env(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (ft_strcmp(env[i], "EMPTY") != 0)
			ft_putendl(env[i]);
	}
}

char	*get_env(char **env, char *path)
{
	char	**tmp;
	char	**arg;
	char	*ret;
	int		i;

	i = -1;
	tmp = env;
	ret = NULL;
	while (tmp[++i])
	{
		arg = ft_strsplit(tmp[i], '=');
		if ((ft_strcmp(arg[0], path)) == 0)
		{
			ret = NULL;
			if (arg[1])
				ret = ft_strdup(arg[1]);
			return (ret);
		}
	}
	return (ret);
}

char	*get_user(char **env)
{
	char	*login;

	login = get_env(env, "USER");
	if (login == NULL)
		login = "$";
	return (login);
}

char	*get_path_prompt(char **env)
{
	char	*path;

	path = get_env(env, "PWD");
	if (path == NULL)
		path = "$";
	return (path);
}
