/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:14:49 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/22 14:10:31 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <curses.h>
#include <termios.h>
#include <unistd.h>
#include <term.h>
#include "../inc/libft.h"

static char *get_env(char **env)
{
    int i;
    int j;
    char *buf;

    i = 0;
    j = 0;
    while (!ft_strstr(env[i], "TERM"))
        i++;
    buf = ft_strdup("TERM=");
    while(env[i][j] == buf[j])
        j++;
    return (&env[i][j]);
}

static int     voir_touche(void)
{
  char     buffer[3];

  while (1)
  {
    read(0, buffer, 3);
    if (buffer[0] == 27)
      printf("C'est une fleche !\n");
    else if (buffer[0] == 4)
    {
      printf("Ctlr+d, on quitte !\n");
      return (0);
    }
  }
  return (0);
}

int main(int ac, char **av, char **env)
{
    char           *name_term;
    struct termios term;
(void)ac;
(void)av;
  if ((name_term = ft_strdup(get_env(env))) == NULL)
     return (-1);
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
voir_touche();
return (0);
}
