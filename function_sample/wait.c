#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		main()
{
	pid_t	pid;
	pid_t	son_pid;
	int		stat;

	pid = fork();
	if (pid == 0)
	{
		printf("Son : Hello dad, if you reading this i'm alive.\n");
	}
	else
	{
		printf("Computer : I'm waiting\n");
		son_pid = wait(&stat);
		printf("Dad : Cheh son your dead.\n");
		printf("Dad : My PID is = %d and yours was = %d.\n", getpid(), son_pid);
		if (WIFEXITED(stat) == 1)
			printf("return of child was %d.\n", WEXITSTATUS(stat));
	}
	printf("bye\n");
	exit (45);
}
