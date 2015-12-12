/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 22:29:55 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/17 09:39:08 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		size_params(int argc, char **argc)
{
	int size_argv;
	int i;
	int j;

	i = 1;
	j = 0;
	size_argv = 0;
	while (i < argc)
	{
		while (argv[i][j])
			j++;
		size_argv = size_argv + j;
		j = 0;
		i++;
	}
	return (size_argv);
}

void	print

char	*ft_concat_params(int, argc, char **argv)
{
	int i;
	int j;

	dest = (char*)malloc(sizeof(*dest) * size + 1)
}
