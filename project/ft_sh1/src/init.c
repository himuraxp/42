/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 18:37:34 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/03 17:09:12 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int			ft_envlen(char *env)
{
	int		i;
	char	tmp;

	i = -1;
	while (env[++i] != '\0')
	{
		tmp = env[i];
		if (tmp == '=')
			return (i);
	}
	return (i);
}

int			get_env_line(char *name, char **env)
{
	int		i;
	char	**tab;

	tab = env;
	i = -1;
	while (tab[++i])
		if ((ft_strncmp(name, tab[i], ft_envlen(tab[i]))) == 0)
			return (i);
	return (-1);
}

void		change_set(char *name, char *value, char **env)
{
	int		i;
	char	*tmp;

	i = get_env_line(name, env);
	tmp = ft_strjoin(name, "=");
	if (name && value)
		tmp = ft_strjoin(tmp, value);
	if (i != -1)
	{
		env[i] = ft_strdup(tmp);
		return ;
	}
	add_set(name, value, env, i);
}

void		add_set(char *name, char *value, char **env, int check)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strjoin(name, "=");
	if (name && value)
		tmp = ft_strjoin(tmp, value);
	if (check == -1)
	{
		while (env[i])
			i++;
		env[i] = ft_strdup(tmp);
	}
	i++;
	env[i] = NULL;
}

void	init_env(char **env)
{
	change_set("ITERM_PROFILE", "Default", env);
	change_set("COLORFGB", "7;0", env);
	change_set("USER", "$", env);
	change_set("PATH", "/usr/bin", env);
	change_set("TERM", "xterm-256color", env);
}
