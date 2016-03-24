/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 22:56:20 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/02 15:18:12 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	int count;

	count = 0;
	if (s)
	{
		while (s[count] != '\0')
		{
			s[count] = '\0';
			s++;
		}
	}
}