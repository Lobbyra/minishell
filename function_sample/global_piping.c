#include <stdio.h>
#include <unistd.h>
#include "l_libc.h"

void	ft_random(int pipe[2], int count_global)
{
	char	n;
	int		count;
	char	*buf;
	if (count_global != 20 && fork() == 0)
	{
		close(pipe[1]);
		write(1, "1", 1);
		while (get_next_line(pipe[0], &buf))
			printf("i readed : %s\n", buf);
		write(1, "2", 1);
	}
	close (pipe[0]);
	count = rand() % 10;
	while (count <= 0)
		count = rand() % 10;
	while (count)
	{
		n = -1;
		while (n <= 0)
			n = (rand() % 10);
		n += '0';
		printf("n = %c\n", n);
		write(pipe[1], &n, 1);
		count--;
	}
}

int		main()
{
	int count = 20;
	int global_pipe[2];

	pipe(global_pipe);
	while (count)
	{
		if (fork() == 0)
			ft_random(global_pipe, count);
		wait(NULL);
		count--;
	}
	return (0);
}
