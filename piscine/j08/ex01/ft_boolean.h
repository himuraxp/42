/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 13:33:53 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/21 22:03:43 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H

# define FT_BOOLEAN_H
# define EVEN(x) (x % 2) == 0
# define TRUE		1
# define FALSE		0
# define EVEN_MSG	"I have a pair number of arguments.\n"
# define ODD_MSG	"I have an impair number of arguments.\n"
# define SUCCESS	0
# include <unistd.h>

typedef	int	t_bool;
void	ft_putstr(char *str);

#endif
