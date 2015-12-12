/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 20:04:24 by gmarguer          #+#    #+#             */
/*   Updated: 2015/07/30 22:50:51 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_return_error(int code, t_read *read)
{
	read->error = code;
	return (code);
}

void	ft_free(t_read *read)
{
	free(read->buf);
	free(read->str);
	free(read);
}
