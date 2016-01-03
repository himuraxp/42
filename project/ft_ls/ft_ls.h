/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 17:51:05 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/03 20:44:06 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <unistd.h>

void	ft_col(struct dirent *play, size_t max);
void	ft_ls(char *path, char *arg);
void	ft_stat(char *path);
int		ft_len(char *str);
int		ft_arg(int ac, char **av, int i);
int		ft_ls_hidden(char *str);

#endif
