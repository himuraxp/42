/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 13:29:09 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/04 15:58:33 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

t_list	*get_lst_param(char **env)
{
	t_list		*lst;
	int			i;

	i = 0;
	lst = NULL;
	while (env[i])
	{
		lst = ft_lstnew(env[i], ft_strlen(env[i]));
		lst = lst->next;
		i++;
	}
	return (lst);
}

void		sig_handler(int signo)
{
	if (signo == SIGINT)
		ft_putendl("received : SIGINT");
	if (signo == SIGKILL)
		ft_putendl("received : SIGKILL");
	if (signo == SIGSTOP)
		ft_putendl("received : SIGSTOP");
	exit(0);
}

int		my_raw(struct termios *term)
{
	if (tcgetattr(0, term))
		return (-1);
	term->c_cc[VMIN] = 0;
	term->c_cc[VTIME] = 0;
	term->c_lflag &= ~(ECHO | ICANON);
	term->c_cflag &= ~(CREAD);
	tcsetattr(0, TCSANOW, term);
	return (0);
}

int		my_unraw(struct termios *term)
{
	if (tcgetattr(0, term))
		return (-1);
	term->c_lflag |= (ECHO|ICANON|ISIG|ECHOE|ECHOK|ECHONL);
	term->c_oflag |= (OPOST);
	tcsetattr(0, TCSADRAIN, term);
	return (0);
}

int		ft_select(t_list *lst, struct termios *term)
{
	int 	i;
	char	*line;

	i = 1;
	while (42)
	{
		while (get_next_line(0, &line))
		{
			if (ft_strcmp(line, " ") == 0)
				ft_putendl("space");
			else if (ft_strcmp(line, "\033[A") ==  0)
				ft_putendl("arrow up");
			else if (ft_strcmp(line, "\033[B") ==  0)
				ft_putendl("arrow down");
			else if (ft_strcmp(line, "\033[C") ==  0)
				ft_putendl("arrow right");
			else if (ft_strcmp(line, "\033[D") ==  0)
				ft_putendl("arrow left");
		}
	}
	(void)term;
	(void)lst;
	return (0);
}
