/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 19:13:23 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/03 09:49:56 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	get_setenv(char **arg, char *n, char **g_env)
{
	if ((ft_strncmp(arg[0], "setenv", 6)) == 0)
	{
		if (arg[1] && arg[2])
			change_set(arg[1], arg[2], g_env);
		if (arg[1] && arg[2] == NULL)
			change_set(arg[1], n, g_env);
	}
}

void	print_setenv(char **arg, char **env)
{
	char	*value;

	if ((ft_strncmp(arg[0], "printenv", 8)) == 0)
	{
		if (arg[1])
		{
			value = get_env(env, arg[1]);
			if (value != NULL)
				ft_putendl(value);
			return ;
		}
		print_env(env);
	}
}

void		get_unsetenv(char *name, char **env)
{
	char	**tab;
	int		len;
	int		i;

	if (name)
	{
		len = get_env_line(name, env);
		i = 0;
		if (len != -1)
		{
			tab = env;
			while (tab[i] != tab[len])
				i++;
			env[i] = ft_strdup("EMPTY");
		}
	}
}

void		free_arg(char *arg, char **arg_ptr)
{
	free(arg);
	free(arg_ptr);
}
