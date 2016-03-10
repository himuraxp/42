/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:43:26 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/10 14:30:36 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int				change_oldpwd(t_lenv **env)
{
	t_lenv	*oldpwd;
	t_lenv	*tmp;

	tmp = get_lenv(*env, "PWD");
	oldpwd = get_lenv(*env, "OLDPWD");
	if (!tmp || !oldpwd || !tmp->value || !oldpwd->value)
		return (0);
	free(oldpwd->value);
	oldpwd->value = ft_strdup(tmp->value);
	return (1);
}

int				check_error(char *new_path, char *path)
{
	if (chdir(new_path) == 0 && access(new_path, R_OK) != 0)
	{
		ft_putendl(ft_strjoin("cd: ", ft_strjoin(path, " permission denied")));
		return (0);
	}
	if (chdir(new_path) != 0)
	{
		ft_putendl(ft_strjoin("cd: no such file or directory: ", path));
		return (0);
	}
	return (1);
}

int				check_path_spe(char *path)
{
	char	*str;

	str = ft_strdup(path);
	if (check_error(str, path))
		return (1);
	return (0);
}

int				check_path(t_lenv *env, char *path)
{
	t_lenv	*tmp;
	char	*str;

	tmp = get_lenv(env, "PWD");
	if (tmp == NULL)
		return (1);
	str = ft_strdup(tmp->value);
	str = ft_strjoin(tmp->value, ft_strjoin("/", path));
	if (check_error(str, path))
		return (1);
	return (0);
}
