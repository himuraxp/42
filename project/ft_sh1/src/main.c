/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:43:19 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/20 20:01:24 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void		print_prompt(char *name)
{
	ft_putstr(name);
	ft_putstr(" $>> ");
}

void		handler(void)
{
	if (g_bool == 0)
	{
		g_bool = 2;
		ft_putchar('\n');
		print_prompt("name");
	}
	else
	{
		ft_putchar('\n');
		if (g_bool != 1)
			print_prompt("name");
	}
}

char	*get_user(t_lenv *env)
{
	char	*login;

	login = NULL;
	while (env)
	{
		if (ft_strcmp(env->name, "USER") == 0)
		{
			login = ft_strdup(env->value);
			return (login);
		}
		env++;
	}
	if (login == NULL)
		login = "$";
	return (login);
}

int			main(int ac, char **av, char **env)
{
	t_lenv		*env_cpy;
	char		*name;
	char		*line;
	int			i;

	i = 0;
	(void)ac;
	(void)av;
	env_cpy = create_list(env);
	name = get_user(env);
	print_prompt(name);
	signal(SIGINT, (void(*)())handler);
	while (get_next_line(0, &line))
		env_cpy = core(env_cpy, line);
	return (0);
}
