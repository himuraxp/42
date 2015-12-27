/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:14:11 by ylarbi            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/12/22 20:28:16 by ylarbi           ###   ########.fr       */
=======
/*   Updated: 2015/12/26 09:48:19 by ylarbi           ###   ########.fr       */
>>>>>>> 4f42a4fe446ce3cdedb9b97a5e28297c741c7aaf
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char *str;
	int fd;

	fd = open("txt", O_RDONLY);
	get_next_line(fd, &str);
		printf("%s", str);
	return (0);
}
