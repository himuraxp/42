/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 15:55:28 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/29 16:11:55 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char	*ft_strcpy(char *s1, char *s2);

int		main(void)
{
	char dst[5];
	char src[5] = " t t";

		printf("ft_src : %s\n", src);
		printf("src : %s\n", src);
		strcpy(dst, src);
		ft_strcpy(dst, src);
		printf("ft_dst : %s\n", dst);
		printf("dst : %s\n", dst);
}
