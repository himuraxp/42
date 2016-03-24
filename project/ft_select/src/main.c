/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:14:49 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/24 13:02:28 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static char *get_env(char **env)
{
	int i;
	int j;
	char *buf;

	i = 0;
	j = 0;
	while (!ft_strstr(env[i], "TERM="))
		i++;
	buf = ft_strdup("TERM=");
	while(env[i][j] == buf[j])
		j++;
	return (&env[i][j]);
}

static int     clean_screen(void)
{
	char	*result;

	if ((result = tgetstr("cl", NULL)) == NULL)
		return (-1);
	else
	{
		tputs(result, 0, tputs_putchar);
	}
	return (0);
}

static int     show_key(void)
{
	char	buf[3];
	int		len;

	len = 0;
	while (1)
	{
		read(0, buf, 3);
		printf("%d %d %d\n", buf[0], buf[1], buf[2]);
		if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68)
			message("-> fleche gauche");
		else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67)
			message("-> fleche droite");
		else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
			message("-> fleche haut");
		else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
			message("-> fleche bas");
		else if (buf[0] == 4)
		{
			printf("Ctlr+d, on quitte !\n");
			return (0);
		}
		else if (buf[0] == 2)
		{
			clean_screen();
		}
	}
	return (0);
}

int main(int ac, char **av, char **env)
{
	char			*name_term;
	struct termios	term;

	(void)ac;
	(void)av;
	if ((name_term = ft_strdup(get_env(env))) == NULL)
		name_term = ft_strdup("Default");
	ft_putendl(name_term);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	// remplis la structure termios des possibilités du terminal.
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	// On applique les changements :
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	show_key();
		return (0);
}
