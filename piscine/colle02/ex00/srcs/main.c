/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 15:36:03 by chdenis           #+#    #+#             */
/*   Updated: 2015/07/26 19:22:39 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "constants.h"
#include "parse.h"
#include "fts.h"

int main(void)
{
	char	*buff;
	int		ret;
	int		length;

	buff = (char*)malloc(sizeof(char) * (BUFF + 1));
	length = 0;
	while ((ret = read(0, buff + length, 30)))
	{
		length += ret;
		if (ret == -1)
			return (0);
	}
	buff[length] = 0;
	if (parse(buff) == 0)
		ft_putstr("aucune");
	ft_putstr("\n");
	free(buff);
	return (0);
}
