/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 12:11:58 by ylarbi            #+#    #+#             */
/*   Updated: 2016/03/24 14:18:40 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	message(char *str)
{
	int		i;
	int		len;
	char	*buf;

	i = 0;
	buf = NULL;
	len = ft_strlen(str);
	if (str[i] == '-' && str[i + 1] == '>')
	{
		buf = ft_strnew(len);
		ft_strcat(buf, "\033[30;1m->\033[35m");
		i = 2;
		ft_strcat(buf, &str[i]);
		len += 12;
		buf[len + 1] = '\0';
		ft_putendl(buf);
		ft_putstr("\033[0m");
	}
	free(buf);
}
