/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 17:51:05 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/02 18:34:48 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <unistd.h>

void	ft_ls(char *path);
void	ft_stat(char *path);
/*struct stat {
		dev_t    st_dev;
		ino_t    st_ino;
		mode_t   st_mode;
		nlink_t  st_nlink;
		uid_t    st_uid;
		gid_t    st_gid;
		dev_t    st_rdev;
		struct timespec st_atimespec;
		struct timespec st_mtimespec;
		struct timespec st_ctimespec;
		off_t    st_size;
		quad_t   st_blocks;
		u_long   st_blksize;
		u_long   st_flags;
		u_long   st_gen;
};*/

#endif
