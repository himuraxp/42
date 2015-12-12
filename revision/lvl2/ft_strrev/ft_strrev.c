/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 17:10:26 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/30 18:46:30 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strrev(char *str)
{
	int i;
	char *temp;
	int j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		while (str[i] != '\0')
		{
			i++;
		}
		str[j] = str[i];
		temp = str[j];
		i--;
		j++;
	}
	printf("%s", temp);
	return (temp);
}

int		main(void)
{
	char *str;

	str = "salut";
	printf("%s\n", "Salut\0");
	ft_strrev(str);
	return (0);
}
