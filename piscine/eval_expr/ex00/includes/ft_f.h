/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 10:54:28 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/26 11:24:47 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_F_H
# define FT_F_H
# include <unistd.h>
# include <stdlib.h>

int		ft_parse_nbr(char **ps);
int		do_op(int a, char op, int b);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putnbr(int nb);
int		eval_expr(char *str);
int		eval_first(char **ps);
int		eval_sec(char **ps);
char	*suppr_spaces(char *str);

#endif
