/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/24 22:34:58 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/26 11:15:35 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_f.h"

int		eval_sec(char **ps)
{
	int		left;
	int		right;
	char	op;

	left = ft_parse_nbr(ps);
	while ((*ps)[0] != '\0' && (*ps)[0] != ')')
	{
		op = (*ps)[0];
		*ps = *ps + 1;
		if (op == '+' || op == '-')
			right = eval_first(ps);
		else
			right = ft_parse_nbr(ps);
		left = do_op(left, op, right);
	}
	return (left);
}

int		eval_first(char **ps)
{
	int		left;
	int		right;
	char	op;

	left = ft_parse_nbr(ps);
	while ((*ps)[0] == '*' || (*ps)[0] == '/' || (*ps)[0] == '%')
	{
		op = (*ps)[0];
		*ps = *ps + 1;
		right = ft_parse_nbr(ps);
		left = do_op(left, op, right);
	}
	return (left);
}

int		eval_expr(char *str)
{
	str = suppr_spaces(str);
	if (str[0] == '\0')
		return (0);
	return (eval_sec(&str));
}
