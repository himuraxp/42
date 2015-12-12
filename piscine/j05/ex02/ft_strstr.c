/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 11:27:26 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/14 15:00:31 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int k;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			k = i;
			while (to_find[j] != '\0' && str[k] != '\0' && to_find[j] != str[k])
			{
				j++;
				k++;
			}
			if (to_find[j] == str[k])
				return (&str[i]);
		}
		else
			i++;
	}
	return (0);
}
