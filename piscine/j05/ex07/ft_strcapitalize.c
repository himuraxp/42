/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 17:41:59 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/14 19:21:13 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	lowcase(char *c)
{
	if (*c >= 'a' && *c <= 'z')
	{
		*c -= 32;
	}
}

void	upcase(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
	{
		*c += 32;
	}
}

int		alpha(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int test;
	int i;

	i = 0;
	test = 1;
	while (str[i] != '\0')
	{
		if (alpha(str[i]))
		{
			if (test)
				lowcase(str + i);
			else
				upcase(str + i);
			test = 0;
		}
		else
			test = 1;
		i++;
	}
	return (str);
}
