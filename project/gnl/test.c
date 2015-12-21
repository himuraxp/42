/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 11:52:21 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/21 12:29:13 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     my_cat_buf_to_line(char *line, char *buf, char *save)
{
  int   i;
  int   j;

  j = 0;
  i = my_strlen(line);
  while (buf[j])
    {
      if (buf[j] == '\n' || i == LINE_LEN)
        {
          line[i] = 0;
          if (buf[j] == '\n')
            j++;
          save = my_strcpy(save, buf + j);
          return (1);
        }
      line[i++] = buf[j++];
    }
  save[0] = 0;
  line[i] = 0;
  return (0);
}

char    *get_next_line(const int fd)
{
  static char   save[BUF_LEN];
  char  buf[BUF_LEN + 1];
  char  *line;
  int   len;

  line = xmalloc(sizeof(char) * LINE_LEN);
  line[0] = 0;
  if (my_cat_buf_to_line(line, save, save) == 1)
    return (line);
  while ((len = read(fd, buf, BUF_LEN)) > 0 && LINE_LEN > 0)
    {
      buf[len] = 0;
      if (my_cat_buf_to_line(line, buf, save) == 1)
        return (line);
    }
  if (line && line[0] != 0)
    return (line);
  return (NULL);
}
