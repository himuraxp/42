/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 19:37:05 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/03 15:41:30 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void		check_cd(char *path)
{
	struct stat		sb;

	stat(path, &sb);
	if ((sb.st_mode & S_IFMT) == S_IFDIR)
	{
		if (access(path, R_OK) == -1)
		{
			ft_putstr("cd: permission denied: ");
			ft_str_color(path, "red", "bold");
            ft_putchar('\n');
			return ;
		}
	}
	else
	{
		if ((sb.st_mode & S_IFMT) != S_IFDIR && access(path, F_OK) == 0)
		{
			ft_putstr("cd: not a directory: ");
            ft_str_color(path, "red", "bold");
			ft_putchar('\n');
			return ;
		}
		ft_putstr("cd: no such file or directory: ");
		ft_str_color(path, "red", "bold");
        ft_putchar('\n');
	}
}

void	get_check_cd(char **arg, char *path, char *last_path, char **env)
{
	int		ret_dir;

	if (arg[1][0] == '~')
	{
		path = ft_strjoin(path, arg[1] + 1);
		check_cd(path);
		last_pwd(last_path, env);
		ret_dir = chdir(path);
		pwd(ret_dir, env);
		return ;
	}
	if (arg[1][0] == '-')
	{
		path = ft_strjoin(get_env(env, "OLDPWD"), arg[1] + 1);
		check_cd(path);
		last_pwd(last_path, env);
		ret_dir = chdir(path);
		pwd(ret_dir, env);
		return ;
	}
	check_cd(arg[1]);
	last_pwd(last_path, env);
	ret_dir = chdir(arg[1]);
	pwd(ret_dir, env);
	return ;
}

void		pwd(int ret_dir, char **env)
{
	char	buf[2048];

	if (ret_dir == 0)
	{
		getcwd(buf, sizeof(buf));
		change_set("PWD", buf, env);
	}
}

void		last_pwd(char *last_path, char **env)
{
	char	buf[2048];

	getcwd(buf, sizeof(buf));
	change_set("OLDPWD", buf, env);
	last_path = ft_strdup(buf);
}

void		cd(char **arg, char **env)
{
	int		ret_dir;
	char	*path;
	char	*last_path;

	path = get_env(env, "HOME");
    last_path = NULL;
	if ((ft_strncmp(arg[0], "cd", 2)) == 0 && arg[1] != NULL)
	{
		get_check_cd(arg, path, last_path, env);
	}
	else if ((ft_strncmp(arg[0], "cd", 2)) == 0 && arg[1] == NULL)
	{
		check_cd(path);
		last_pwd(last_path, env);
		ret_dir = chdir(path);
		pwd(ret_dir, env);
		return ;
	}
}
