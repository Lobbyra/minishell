#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int		main()
{
	int	pid1;
	int	pid2;
	int	pid3;
	int	pid4;

	if ((pid1 = fork()) == 0)
	{
		sleep(6);
		printf("Child 1 killed.\n");
		exit(1);
	}
	else if ((pid2 = fork()) == 0)
	{
		sleep(7);
		printf("Child 2 killed.\n");
		exit(1);
	}
	else if ((pid3 = fork()) == 0)
	{
		sleep(5);
		printf("Child 3 killed.\n");
		exit(1);
	}
	else if ((pid4 = fork()) == 0)
	{
		sleep(7);
		printf("Child 4 killed.\n");
		exit(1);
	}
	else
	{
		printf("Computer : I'm waiting for the child3 Tommas.\n");
		waitpid(pid3, NULL, WUNTRACED);
		printf("Computer : I'm waiting for the child1 Tom.\n");
		waitpid(pid1, NULL, WUNTRACED);
		printf("Computer : I'm waiting for others children.\n");
		waitpid(-1, NULL, WUNTRACED);
		printf("Computer : NICE ALL CHILDREN ARE DEAD YEY !.\n");
	}
	printf("bye\n");
	return (42);
}
