/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 12:27:39 by ylarbi            #+#    #+#             */
/*   Updated: 2015/07/17 14:52:41 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_STRING_H__
#define __FT_STRING_H__
#include <string.h>
#define SAVE_AUSTIN_POWERS "Save Austin"
#endif

typedef struct	s_perso
{
	char	*profession;
	char	*name;
	float	life;
	int		age;

}				t_perso;
