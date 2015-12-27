/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 11:16:27 by ylarbi            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/12/22 20:17:21 by ylarbi           ###   ########.fr       */
=======
/*   Updated: 2015/12/26 09:57:01 by ylarbi           ###   ########.fr       */
>>>>>>> 4f42a4fe446ce3cdedb9b97a5e28297c741c7aaf
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "./libft/libft.h"
# define BUFF_SIZE 32

int		get_next_line(int const fd, char **line);

#endif
