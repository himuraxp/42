/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 23:35:35 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/10 22:45:32 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putchar_space(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb(void)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = 0;
	while (n1 <= 7)
	{
		n2 = n1 + 1;
		while (n2 <= 8)
		{
			n3 = n2 + 1;
			while (n3 <= 9)
			{
				ft_putchar(n1 + '0');
				ft_putchar(n2 + '0');
				ft_putchar(n3 + '0');
				if (!(n1 == 7))
					ft_putchar_space();
				n3++;
			}
			n2++;
		}
		n1++;
	}
	ft_putchar('\n');
}
