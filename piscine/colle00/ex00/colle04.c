/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 20:03:39 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/12 22:19:40 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		colle(int x, int y)
{
	int line;
	int col;

	line = 1;
	while (line <= y)
	{
		col = 1;
		while (col <= x)
		{
			if ((line == 1 && col == 1) || (line == y && col == x
						&& line > 1 && col > 1))
				ft_putchar('A');
			else if ((line == y && col == 1) || (col == x && line == 1))
				ft_putchar('C');
			else if ((line > 1 && (col == 1 || col == x)) || (col > 1
						&& (line == 1 || line == y)))
				ft_putchar('B');
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		line++;
	}
	return (0);
}
