#include <stdio.h>
#include <unistd.h>
#include <libgen.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include "libc_lobb/headers/l_libc.h"
#include <fcntl.h>

/*
Ce POC est une demonstration de ce genre de chose :
echo "Hello World" > log.txt | cat
La chaine doit aller dans le fichier ET etre afficher par cat.
Donc pour chaque executable lancé, tout la stdout de ce programme doit aller dans un fichier log.txt et dans la stdout.
*/

char	**ll_strs_nuller(char **tab, unsigned int size)
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
	int		fd;
	char	*buf;
	pid_t	child;
	char	**arg;
	int		pipe1[2];
	int		pipe2[2];
	pid_t	child_file;

	pipe(pipe1);
	pipe(pipe2);
	if ((child_file = fork()) == 0)
	{
		errno = 0;
		if ((child = fork()) == 0)
		{
			close(pipe1[0]);
			dup2(pipe1[1], 1);
			arg = ll_strs_nuller(argv + 1, argc - 1);
			free(arg[0]);
			arg[0] = strdup(basename(argv[1]));
			execve(argv[1], arg, envp);
		}
		if (errno != 0)
			printf("%s", strerror(errno));
		close(pipe1[1]);
		close(pipe2[0]);
		wait(NULL);
		fd = open("log.txt", O_WRONLY | O_CREAT | S_IRUSR, S_IRWXU);
		while (get_next_line(pipe1[0], &buf))
		{
			write(fd, buf, strlen(buf));
			write(pipe2[1], buf, strlen(buf));
		}
		close(pipe2[1]);
		exit(0);
	}
	else
	{
		int ret;
		close(pipe1[1]);
		close(pipe2[1]);
		signal(SIGINT, SIG_IGN);
		wait(NULL);
		while ((ret = get_next_line(pipe2[0], &buf)))
			printf("%s", buf);
		if (ret == 0)
			printf("%s", buf);
	}
	return (0);
}
