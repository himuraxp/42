/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 01:03:47 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/03 16:17:39 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		get_access(char *arg)
{
	int		ret;

	ret = 0;
	if ((ft_strcmp(arg, "cd")) == 0)
		ret = 1;
	if ((ft_strcmp(arg, "env")) == 0)
		ret = 1;
	if ((ft_strcmp(arg, "setenv")) == 0)
		ret = 1;
	if ((ft_strcmp(arg, "unsetenv")) == 0)
		ret = 1;
	if ((ft_strcmp(arg, "printenv")) == 0)
		ret = 1;
	if ((ft_strncmp(arg, "/", 1)) == 0)
		ret = 2;
	if ((ft_strncmp(arg, "./", 2)) == 0)
		ret = 2;
	return (ret);
}

/*void	signal_handler(int sign)
{
	(void)sign;
	ft_putstr("\n");
	prompt(g_login);
}

void	check_sign(void)
{
	signal(SIGINT, signal_handler);
}*/
