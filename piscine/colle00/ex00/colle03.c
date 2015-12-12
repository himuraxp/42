/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 22:37:24 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/12 10:04:41 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		colle(int x, int y)
{
	int line;
	int col;

	line = 1;
	col = 1;
	while (line <= y)
	{
		while (col <= x)
		{
			if ((col == 1) && (line == 1 || line == y))
				ft_putchar('A');
			else if ((col == x) && (line == 1 || line == y))
				ft_putchar('C');
			else if (col == 1 || col == x || line == 1 || line == y)
				ft_putchar('B');
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		col = 1;
		line++;
	}
	return (0);
}
