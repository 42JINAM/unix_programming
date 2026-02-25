/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cool <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:46:42 by cool              #+#    #+#             */
/*   Updated: 2026/02/25 16:09:16 by cool             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/apue.h"
#include <dirent.h>


int	main(int argc, char *argv[])
{
	DIR				*dp;
	struct dirent	*dirp;

	if (argc != 2)
		err_quit("usage: ls directory_name");
	dp = opendir(argv[1]);
	if (dp == NULL)
		err_sys("can't open %s", argv[1]);
	dirp = readdir(dp);
	while (dirp != NULL)
	{
		printf("%s\n", dirp->d_name);
		dirp = readdir(dp);
	}
	closedir(dp);
	exit(0);
}
