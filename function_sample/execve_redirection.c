#include <stdio.h>
#include <unistd.h>
#include <libgen.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include "libc_lobb/headers/l_libc.h"

char		**ll_strs_nuller(char **tab, unsigned int size)
{
	char			**new;
	unsigned int	i;

	i = 0;
	if (!tab)
		return (NULL);
	if (!(new = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		new[i] = strdup(tab[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

int		main(int argc, char **argv, char **envp)
{
	char	**arg;
	pid_t	child;
	int		pipe1[2];
	char	*buf;

	pipe(pipe1);
	if ((child = fork()) == 0)
	{
		close(pipe1[0]);
		dup2(pipe1[1], 1); // Redirect all stdout in pipe1 write-side
		arg = ll_strs_nuller(argv + 1, argc - 1); //argv + 1 to avoid a.out
		free(arg[0]); // Removing first "/usr/bin" things to put basename in the first block.
		arg[0] = strdup(basename(argv[1])); // Place file name part in the first case;
		execve(argv[1], arg, envp);
		close(pipe1[1]);
		exit(0);
	}
	else
	{
		close(pipe1[1]);
		signal(SIGINT, SIG_IGN); //Used to avoid CTRL+C parent kill. SIG_IGN mean signal ignore.
		wait(NULL);
		while (get_next_line(pipe1[0], &buf))
			printf("%s", buf);
		close(pipe1[0]);
	}
	return (0);
}
