/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 18:14:37 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/29 19:07:44 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	repeat_alpha(char *str);

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	repeat_alpha(argv[1]);
	return (0);
}
