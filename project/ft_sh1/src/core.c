/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 15:08:50 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/20 12:17:27 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

t_lenv			*core(t_lenv *env, char *line)
{
	char		**param;

	g_bool = 0;
	param = ft_split_whitespaces(line);
	if (param[0] && check_param(param[0]) == 0)
		exec_core(env, param);
	else if (param[0] && check_param(param[0]) == 1)
		env = ft_parse(env, param);
	if (g_bool != 2)
		print_prompt();
	g_bool = 0;
	return (env);
}

void			exec_core(t_lenv *env, char **param)
{
	char		*exec;

	param = check_exec_param(env, param);
	g_bool = 0;
	if (!fork())
	{
		g_bool = 1;
		if (param && param[0][0] == '/' && access(param[0], X_OK) == 0)
			execve(param[0], param, list_to_char(env));
		else if (param && param[0][0] == '.' && param[0][1] == '/' &&
				access(param[0], X_OK) == 0)
			execve(param[0], param, list_to_char(env));
		else if (param && (exec = check_exec(param[0], env)) != NULL)
			execve(exec, param, list_to_char(env));
		else
		{
			ft_putstr(param[0]);
			ft_putstr(": command not found\n");
		}
		exit(0);
	}
	else
		wait(0);
}