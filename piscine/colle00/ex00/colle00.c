/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 12:03:20 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/12 12:23:09 by ylarbi           ###   ########.fr       */
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
			if ((col == 1 || col == x) && (line == 1 || line == y))
				ft_putchar('o');
			else if (line == 1 || line == y)
				ft_putchar('-');
			else if (col == 1 || col == x)
				ft_putchar('|');
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
