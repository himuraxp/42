/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:45:16 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/10 14:30:45 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	ft_exit(char **param)
{
	if (param[1])
	{
		if (param[2])
			ft_putendl("exit: too many arguments");
		else
			exit(ft_atoi(param[1]));
	}
	else
		exit(0);
}
