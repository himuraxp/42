/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:45:06 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/10 14:30:58 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void			ft_unset_env(t_lenv **env, char **param)
{
	t_lenv		*tmp;
	int			i;

	i = 0;
	tmp = *env;
	if (!param[1])
	{
		ft_putendl("unsetenv: no argument given");
		return ;
	}
	while (param[++i])
	{
		tmp = *env;
		while (tmp)
		{
			if (ft_strcmp(tmp->name + 1, param[i]) == 0)
				*env = ft_env_relink(*env, tmp->name);
			tmp = tmp->next;
		}
	}
}
