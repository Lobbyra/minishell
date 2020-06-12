#include <stdio.h>
#include <unistd.h>
#include <sys/errno.h>
#include <string.h>

/*
**	There is one condition but both of two printf() will be executed.
*/

int		main()
{
	pid_t child;

	errno = 0;
	child = fork();
	if (child == 0) // Child = 0 if this is the child process run the if.
		printf("I'm 5 year old.\n");
	else if (child > 0) // Child != 0 if this is the parent. 
		printf("I'm 50 year old.\n");
	else if (child == -1)
		printf("%s\n", strerror(errno));
	return (0);
}
