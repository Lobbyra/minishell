#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int		main()
{
	int				status;
	pid_t			child;
	struct rusage	c_usage;
	int				i;
	float			temp;

	i = 0;
	temp = 0;
	child = fork();
	if (child == 0)
	{
		while (i < 99999999) //used to do work by child
		{
			temp *= (i * 4) * (temp / 2) * 5 / 2.3;
			i++;
		}
		return (42);
	}
	else
	{
		wait4(child, &status, 0, &c_usage);
		printf("Informations about dead child :\n");
		printf("Len of life of child was %ld.%d seconds.\n", c_usage.ru_stime.tv_sec, c_usage.ru_stime.tv_usec);
	}
	return (0);
}
