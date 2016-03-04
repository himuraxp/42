/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_color_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:41:01 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/04 19:19:06 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	s_buf(char *s_buf, char *buf, t_opt *type)
{
    buf = ft_strnew((ft_strlen(c_buf) + 6));
    ft_strcpy(buf, type->init);
    buf = ft_strjoin(buf, c_buf);
	buf = ft_strjoin(buf, &type->end);
}

void	c_buf(char *c_buf, char *buf, t_opt *type)
{
	buf = ft_strnew((ft_strlen(s_buf) + 6));
	ft_strcpy(buf, type->init);
	buf = ft_strjoin(buf, s_buf);
	buf = ft_strjoin(buf, &type->end);
}

void	cs_buf(char *c_buf, char *s_buf, char *buf,  t_opt *type)
{
	buf = ft_strnew((ft_strlen(c_buf) + ft_strlen(s_buf)) + 7);
	ft_strcpy(buf, type->init);
    buf = ft_strjoin(buf, c_buf);
    buf = ft_strjoin(buf, type->sep);
    buf = ft_strjoin(buf, s_buf);
    buf = ft_strjoin(buf, &type->end);
}

char    *opt_cmp(char *color, char *style, t_opt *type)
{
    char *c_buf;
    char *s_buf;
    char *buf;
    int i;
    int j;

    i = -1;
    j = 0;
    while (++i <= 8)
    {
        if (ft_strcmp(color, type->c_name[i]))
            ft_strcpy(c_buf, type->c_name[i]);
        if (ft_strcmp(style, type->s_name[j]) && j <= 5)
            ft_strcpy(s_buf, type->s_name[i]);
        j++;
    }
    if (!s_buf)
		s_buf(s_buf, buf, type);
	else if (!c_buf)
		c_buf(c_buf, buf, type);
	else if (c_buf && s_buf)
		cs_buf(c_buf, s_buf, buf, type);
	else
        buf = NULL;
    return (buf);
}
