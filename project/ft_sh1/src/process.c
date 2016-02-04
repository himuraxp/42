/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:02:24 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/04 16:28:19 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	*get_cmd_path(char *arg, char **env)
{
	int ret;
    char **kill;

	ret = 0;
    kill = env;
	if (ft_strncmp(arg, "/", 1) == 0)
		ret = 1;
	if (ft_strncmp(arg, "./", 2) == 0)
		ret = 1;
	if (ret == 1)
	{
		if (access(arg, F_OK) != 0)
		{
			ft_putstr("cd:");
            ft_str_color(arg, "red", "bold");
            ft_putendl(": no such file or directory");
			arg = NULL;
			return (arg);
		}
		return (arg);
	}
	arg = NULL;
	return (arg);
}

char	*get_path(struct dirent *dirent, DIR *dir, char *arg, char *path)
{
	char			*cmd;

	cmd = NULL;
	while ((dirent = readdir(dir)) != NULL)
	{
		if ((ft_strcmp(dirent->d_name, arg)) == 0)
		{
			arg = ft_strjoin("/", arg);
			cmd = ft_strjoin(path, arg);
			break ;
		}
	}
	return (cmd);
}

char	*get_cmd(char *arg, char **env)
{
    DIR				*dir;
    struct dirent	*dirent;
	char			**path;
	char			*data[2];
	int				i;

	i = -1;
	data[0] = get_env(env, "PATH");
	data[1] = NULL;
    dirent = NULL;
	if (data[0] != NULL && ((path = ft_strsplit(data[0], ':'))))
	{
		while (path[++i] && ((dir = opendir(path[i]))))
		{
			if (dir != NULL)
			{
				data[1] = get_path(dirent, dir, arg, path[i]);
				if (data[1] != NULL)
					break ;
				closedir(dir);
			}
		}
	}
	return ((data[1]) ? data[1] : get_cmd_path(arg, env));
}

void		get_exe(char **arg, char *cmd, char **env)
{
	pid_t	father;

	if (cmd)
	{
		father = fork();
		if (father > 0)
			wait(NULL);
		if (father == 0)
		{
			execve(cmd, arg++, env);
		}
	}
	else
	{
		if ((get_access(arg[0])) == 0)
		{
			ft_putstr("ft_sh1: command not found: ");
			ft_str_color(arg[0], "red", "bold");
            ft_putchar('\n');
		}
	}
}

void	process(char *cmd, char **arg, char **g_env)
{
	char			*n;
//	t_list			*lst;
//	struct termios	term;

	n = NULL;

	if (arg[0])
	{
//		tgetent(NULL, getenv("TERM"));
//			my_raw(&term);
//			signal(SIGINT, sig_handler);
//			signal(SIGSTOP, sig_handler);
//			signal(SIGKILL, sig_handler);
//			lst = get_lst_param(g_env);
//			ft_select(lst, &term);
//			my_unraw(&term);

		if ((ft_strncmp(arg[0], "exit", 4)) == 0)
			exit(0);
		if ((cmd = get_cmd(arg[0], g_env)) != NULL)
	    {
	        if ((ft_strncmp(arg[0], "env", 3)) == 0)
			{
				if (arg[0] && arg[1] == NULL)
					print_env(g_env);
				if (arg[1] && ++arg)
					cmd = exec_env(arg, g_env);
				del_env(arg, g_env);
			}
	        get_setenv(arg, n, g_env);
	        print_setenv(arg, g_env);
	        if ((ft_strncmp(arg[0], "unsetenv", 8)) == 0)
	            get_unsetenv(arg[1], g_env);
	        cd(arg, g_env);
	        if ((get_access(arg[0])) != 1)
	            get_exe(arg, cmd, g_env);
	        if (arg != NULL && cmd != NULL && !(arg = NULL))
	            free_arg(cmd, arg);
		}
    }
}
