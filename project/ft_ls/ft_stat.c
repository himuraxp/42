/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 18:19:57 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/02 20:42:18 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int	ft_stat(char *path)
{
    struct stat	fileStat;

	if(stat(path,&fileStat) < 0)
        return 1;
    ft_putstr("\033[36m------------>\t\t");
    ft_putstr(path);
    ft_putstr("\033[0m\n");
	ft_putstr("Type: \t\t\t");
    ft_putstr((S_ISDIR((fileStat.st_mode))) ? "Directory" : "File");
	ft_putchar('\n');
    ft_putstr("File Size: \t\t");
    ft_putnbr(fileStat.st_size);
    ft_putstr(" bytes\n");
    ft_putstr("Number of Links: \t");
    ft_putnbr(fileStat.st_nlink);
	ft_putchar('\n');
    ft_putstr("File inode: \t\t");
    ft_putnbr(fileStat.st_ino);
	ft_putchar('\n');
    ft_putstr("File Permissions: \t");
    ft_putstr((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    ft_putstr((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    ft_putstr((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    ft_putstr((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    ft_putstr((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    ft_putstr((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    ft_putstr((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    ft_putstr((fileStat.st_mode & S_IROTH) ? "r" : "-");
    ft_putstr((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    ft_putstr((fileStat.st_mode & S_IXOTH) ? "x" : "-");
	ft_putchar('\n');
    ft_putstr("Time of last status change: \t");
    ft_putnbr(fileStat.st_mtime);
	ft_putstr("\n\n");

    ft_putstr("The file ");
    ft_putstr((S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
    ft_putstr(" a symbolic link\n");

    return 0;
}
