/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 20:37:53 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/12 20:47:58 by ylarbi           ###   ########.fr       */
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
			if (line == 1 && (col == 1 || col == x))
				ft_putchar('A');
			else if (line == y && (col == 1 || col == x))
				ft_putchar('C');
			else if (line == 1 || line == y || col == 1 || col == x)
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
