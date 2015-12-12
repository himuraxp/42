/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 17:13:41 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/19 21:10:59 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRILLE_H
# define GRILLE_H

void	init_grille_vide(char ***grille);
int		init_grille(char **argv, char ***grille);
void	print_grille(char **grille);
int		ft_strlen(char *str);
void	free_grille(char ***grille);

#endif
