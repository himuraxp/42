/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 22:44:34 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/29 15:12:25 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		first_word(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '	')
		i++;
	while ((str[i] != ' ' || str[i] != '	') && str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '	')
			return (0);
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	first_word(argv[1]);
	return (0);
}
