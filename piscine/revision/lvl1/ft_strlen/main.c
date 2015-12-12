/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 16:16:29 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/29 16:22:11 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_strlen(char *str);

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	else
		printf("%d\n", ft_strlen(argv[1]));
	return (0);
}
