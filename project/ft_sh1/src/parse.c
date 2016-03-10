/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:24:30 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/10 14:31:12 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

t_lenv			*ft_parse(t_lenv *env, char **param)
{
	if (ft_strcmp(param[0], "cd") == 0)
		ft_cd(&env, param);
	else if (ft_strcmp(param[0], "setenv") == 0)
		ft_setenv(&env, param);
	else if (ft_strcmp(param[0], "unsetenv") == 0)
		ft_unset_env(&env, param);
	else if (ft_strcmp(param[0], "exit") == 0)
		ft_exit(param);
	return (env);
}
