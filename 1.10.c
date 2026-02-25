#include "include/apue.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_types/_pid_t.h>
#include <sys/wait.h>
#include <unistd.h>

static void	sig_int(int)
{
	printf("interrupt\n%% ");
}

int	main(void)
{
	char	buf[MAXLINE];
	pid_t	pid;
	int		status;

	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal_error");
	printf("%% ");
	while (fgets(buf, MAXLINE, stdin) != NULL)
	{
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;
		pid = fork();
		if (pid < 0)
			err_sys("fork error");
		else if (pid == 0)
		{
			execlp(buf, buf, (char *) 0);
			err_ret("couldn't execute: %s", buf);
			exit(127);
		}
		pid = waitpid(pid, &status, 0);
		if (pid < 0)
			err_sys("waitpid error");
		printf("%% ");
	}
	exit(0);
}

