/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 12:08:29 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/12 13:24:45 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int	in;
	int	out;
	char	swap;

	in = 0;
	out = 0;
	while (*(str + in) != '\0')
	{
		in++;
	}
	in--;
	while (in > out)
	{
		swap = str[in];
		str[out] = str[in];
		str[out] = swap;
		in--;
		out++;
	}
	return (str);
}
