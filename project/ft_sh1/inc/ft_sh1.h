/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:34:11 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/04 15:59:33 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include <curses.h>
# include <fcntl.h>
# include <dirent.h>
# include <stdio.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include "libft.h"
# include "color.h"
# include "get_next_line.h"

extern char **g_env;
static char *g_login;
extern char *g_path;

int     ft_envnbr(char **env);
int		ft_envlen(char *env);
int		get_env_line(char *name, char **env);
int		get_access(char *arg);
//int		get_select();

char    *get_user(char **env);
char	*get_path_prompt(char **env);
char	*get_env(char **env, char *path);
char	**get_param(void);
char	*get_cmd(char *arg, char **g_env);
char	*get_path(struct dirent *dirent, DIR *dir, char *arg, char *path);
char	*get_cmd_path(char *arg, char **env);
char	*exec_env(char **arg, char **g_env);
char	*ft_pathjoin(char const *s1, char const *s2);

void    prompt(char *login);
void    prompt_path(char *path, char **env);
void	process(char *cmd, char **arg, char **g_env);
void    ft_envcpy(char **src, char **dst);
void	print_env(char **env);
void	print_setenv(char **arg, char **env);
void	get_setenv(char **arg, char *n, char **g_env);
void	get_unsetenv(char *name, char **env);
void	change_set(char *name, char *value, char **env);
void	add_set(char *name, char *value, char **env, int check);
void	cd(char **arg, char **env);
void	check_cd(char *path);
void	get_check_cd(char **arg, char *path, char *last_path, char **env);
void	get_exe(char **arg, char *cmd, char **env);
void	pwd(int ret_dir, char **env);
void	last_pwd(char *last_path, char **env);
void	free_arg(char *arg, char **arg_ptr);
void    get_line_cmd(char *line);
void	init_env(char **env);
void	del_env(char **arg, char **env);
//void	check_sign(void);
//void	signal_handler(int sign);
t_list	*get_lst_param(char **env);
int		ft_select(t_list *lst, struct termios *term);
int		my_unraw(struct termios *term);
int		my_raw(struct termios *term);
void		sig_handler(int signo);
t_list	*get_lst_param(char **env);
#endif
