/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cool <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:46:42 by cool              #+#    #+#             */
/*   Updated: 2026/02/25 15:05:45 by cool             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/apue.h"
#include <dirent.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_types/_va_list.h>
#include <errno.h>

static void	err_doit(int errnoflag, int error, const char *fmt, va_list ap)
{
	char	buf[MAXLINE];

	vsnprintf(buf, MAXLINE - 1, fmt, ap);
	if (errnoflag)
		snprintf(buf + strlen(buf), MAXLINE - strlen(buf) - 1, \
": %s", strerror(error));
	strcat(buf, "\n");
	fflush(stdout);
	fputs(buf, stderr);
	fflush(NULL);
}

void	err_quit(const char *msg, ...)
{
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

void	err_sys(const char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	exit(1);
}

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
