/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 00:16:10 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/20 11:50:50 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

int		error(int argc, char *argv[]);
void	print_error(void);
char	*block_to_line(char **argv, int x, int y);
int		blockcmp(char **argv);
int		linecmp(char *str);

#endif
