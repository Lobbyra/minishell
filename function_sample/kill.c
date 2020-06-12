#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int		main()
{
	char	key;
	pid_t	child;

	key = -1;
	child = fork();
	if (child == 0)
	{
		sleep(2);
		while (1)
		{
			printf("Hello do you want to be my friend ?\n");
			sleep(1);
		}
	}
	else
	{
		printf("Enter 's' to kill this annoying child...\n");
		printf("Or enter 'i' to stop and 'o' to let i'm talk again...\n");
		while (key != 's')
		{
			while (key != 'i' && key != 'o' && key != 's')
				read(0, &key, 1);
			if (key == 'i')
				kill(child, SIGSTOP);
			else if (key == 'o')
				kill(child, SIGCONT);
			if (key == 'i' || key == 'o')
				key = -1;
		}
		kill(child, SIGKILL);
	}
	return (0);
}
