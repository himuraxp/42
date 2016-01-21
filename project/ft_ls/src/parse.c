/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 18:04:12 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/21 18:55:56 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		is_opt(char *arg)
{
	if (arg[0] == '-' && arg[1] != 0)
		return (1);
	return (0);
}

static int		is_valid_flag(char c)
{
	if (c == 'r' || c == 'R' || c == 'l' || c == 'a' || c == 't' || c == '1'
		|| c == 'd'	|| c == 'p'	|| c == 'U'	|| c == 'c'	|| c == 'u'	|| c == 'S'
		|| c == 'A'	|| c == 'f'	|| c == 'T' || c == 'g'	|| c == 'C')
		return (1);
	return (0);
}

static void		parse_opt(char *opt)
{
	while (*(++opt))
		if (!is_valid_flag(*opt))
			e_illegal_option(*opt);
		else
			activate_flag(*opt);
}

int				parse(int ac, char **av, t_data **arg_lst)
{
	int		i;
	char	accept_flags;

	i = -1;
	accept_flags = 1;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "--") == 0)
			accept_flags = 0;
		else if (accept_flags && is_opt(av[i]))
			parse_opt(av[i]);
		else
		{
			accept_flags = 0;
			lst_push_data(lst_new_data(ft_strdup(av[i]),
			ft_strdup(av[i])), arg_lst);
		}
	}
	return (1);
}
