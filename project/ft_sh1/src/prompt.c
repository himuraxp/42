/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:56:29 by ylarbi            #+#    #+#             */
/*   Updated: 2016/02/03 20:03:15 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	*ft_pathjoin(char const *s1, char const *s2)
{
	char			*new_str;
    char            *sep;
	unsigned int	len;

    sep = strdup("/.../");
	if (s1 && s2)
	{
		len = (ft_strlen(s1) + ft_strlen(s2) + 7);
		if (!(new_str = ft_strnew(len + 1)))
			return (NULL);
        new_str[0] = '/';
		ft_strcat(new_str, s1);
        ft_strcat(new_str, sep);
		ft_strcat(new_str, s2);
        new_str[len] = '/';
		return (new_str);
	}
	return (NULL);
}

void    prompt_path(char *path, char **env)
{
    int     count_dir;
    char    **tmp;

    count_dir = 0;
    path = get_path_prompt(env);
    if (!(tmp = (char**)malloc(sizeof(char*) * (ft_strlen(path) + 1))))
        exit(EXIT_FAILURE);
    if (ft_strncmp(path, "/Users/", 7) == 0)
    {
        tmp = ft_strsplit(path, '/');
        while (tmp[count_dir])
            count_dir++;
        path = ft_pathjoin(tmp[0], tmp[count_dir - 1]);
    }
    prompt(path);
}

void    prompt(char *login)
{
    ft_str_color("-> ", "red", "bold");
    ft_str_color(login, "green", "bold");
    ft_putchar(' ');
}
