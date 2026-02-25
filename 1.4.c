/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cool <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:52:16 by cool              #+#    #+#             */
/*   Updated: 2026/02/25 16:07:48 by cool             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/apue.h"
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/_types/_va_list.h>
#include <unistd.h>

#define BUFFSIZE	4096

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

int	main(void)
{
	int		n;
	char	buf[BUFFSIZE];

	n = read(STDIN_FILENO, buf, BUFFSIZE);
	while (n > 0)
	{
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("read error");
		n = read(STDIN_FILENO, buf, BUFFSIZE);
	}
	if (n < 0)
		err_sys("read error");
	exit(0);
}
