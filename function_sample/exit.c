#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		main()
{
	int		status;
	pid_t	child;

	child = fork();
	if (child == 0)
		exit(42);
	else
	{
		wait(&status);
		printf("Child was terminated by exit and error code was = %d", WEXITSTATUS(status));
	}
	return (0);
}
