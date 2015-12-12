/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 22:19:08 by gmarguer          #+#    #+#             */
/*   Updated: 2015/07/30 23:13:55 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef	struct s_count	t_count;
struct		s_count
{
	int		start;
	int		col;
	int		x;
	int		y;
};

typedef	struct s_read	t_read;
struct		s_read
{
	char	*buf;
	char	**array;
	int		size;
	char	cpy[14];
	char	*str;
	int		buf_size;
	int		start;
	int		r;
	int		line;
	char	empty;
	char	used;
	char	filling;
	int		error;
	char	*temp;
};

typedef	struct s_seek	t_seek;
struct		s_seek
{
	int		ymax;
	int		xmax;
	int		ymin;
	int		xmin;
	int		tempy;
	int		tempx;
	int		savey;
	int		savex;
	int		size;
	char	empty;
	char	used;
	char	filling;
	int		x;
	int		y;
	int		nextx;
};

int			ft_read(int o, t_read *read);
int			ft_open(char *file, t_read *read);
void		ft_bsq(char *file, int param);
int			ft_len(char *str);
int			ft_join(t_read *read, char c);
int			ft_atoiv2(char *str);
int			ft_handling(t_read *read);
t_seek		*ft_create_elem(t_read *read);
t_count		*ft_create_i(int value);
t_read		*ft_create_r();
int			ft_create_2d(t_read *read);
char		*ft_createmalloc(int size, t_read *read);
int			ft_seek(t_read *read);
int			ft_return_error(int code, t_read *read);
int			ft_modif_item(t_read *read, int i);
int			ft_first_line(t_read *read);
int			ft_modif_item2(t_read *read);
int			ft_second_line(t_read *read);
char		ft_dupchar(char c);
int			ft_all(t_read *read);
void		ft_putkebab(t_read *read);
char		*ft_dup(char *dest, char *str);
void		ft_free(t_read *read);

#endif
