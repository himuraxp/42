/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:43:19 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/04 17:47:28 by ylarbi           ###   ########.fr       */
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
		print_prompt("$");
	}
	else
	{
		ft_putchar('\n');
		if (g_bool != 1)
			print_prompt("$");
	}
}

char	*get_user(t_lenv *env)
{
	while (env)
	{
		if (ft_strcmp(env->name, "$USER") == 0)
			return (ft_strdup(env->value));
		env = env->next;
	}
	return (ft_strdup("$"));
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
	name = get_user(env_cpy);
	print_prompt(name);
	signal(SIGINT, (void(*)())handler);
	while (get_next_line(0, &line))
		env_cpy = core(env_cpy, line, name);
	return (0);
}
