/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 10:58:43 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/12 20:01:12 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	sastantua(int size)
{
	int space;
	int col;
	int line;
	int i;
	int z;

	i = 1;
	z = 0;
	col = 2;
	line =  3;
	if (size > 0)
	{
		while (i <= size)
		{
			space = space + 6 + z;
			if (i > 1)
			ft_putchar('*');
		col--;
		}
		ft_putchar('\n');
	line--;
	}
}

int main(void)
{
	int nbr;

	nbr = 5;
	sastantua(nbr);
	return (0);
}

