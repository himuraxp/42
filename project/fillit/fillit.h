/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 19:39:55 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/12 18:35:17 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUF_SIZE 21

typedef	struct s_item	t_item;

struct					s_item
{
	char	id;
	int		*inter;
	int		used;
	int		yx[4][2];
	int		xmin;
	int		xmax;
	int		ymax;
	t_item	*next;
};

typedef	struct s_global	t_global;

struct					s_global
{
	int		nb;
	t_item	*item;
	int		size;
	int		space;
	int		maxspace;
	int		error;
	int		fd;
	char	**square;
	char	*file;
	char	*buf;
	int		used;
};

typedef	struct s_piece	t_piece;

struct					s_piece
{
	int		piece[26];
	//piece = {12,8,4,0,5,1,8,4,0,9,5,1,12,8,4,0,13,9,5,1,16,12,8,4,0,17};
};


int				ft_open(t_global *global);
int				ft_read(t_global *global);
int				ft_parse(t_global *global);
int				ft_create_item(t_global *global);
int				ft_square(t_global *global);
t_global		*ft_create_global(char *file);
void			fillit(char *file);
int				ft_error(t_global *global, int id);
unsigned int	ft_strlen(char *str);
char			*ft_strsub(char *s, unsigned int start, int len);
void			ft_write_square(t_global *global);
int				ft_resolve(t_global *global, int y, int x);
void			freesquare(t_global *global);
int				ft_write_item(t_global *global, t_item *item, int y, int x);
void			ft_index_item(t_global *global);
void			ft_inter(t_global *global);

#endif
