#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>

void		l_putstr_fd(char *s, int fd)
{
	if (s && fd > 0)
	{
		while (*s)
		{
			write(fd, &(*s), 1);
			s++;
		}
	}
}

void	l_putstrs_fd(char **argv, char *sep, int fd)
{
	if (argv && fd > 0)
	{
		while (*argv)
		{
			l_putstr_fd(*argv, fd);
			l_putstr_fd(sep, fd);
			argv++;
		}
	}
}

char		**l_strs_nuller(char **tab, unsigned int size)
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
	pid_t	child;
	char	**arg;

	if (argc > 1)
	{
		errno = 0;
		arg = l_strs_nuller(argv + 1, argc - 1);
		free(arg[0]);
		arg[0] = strdup(basename(argv[1]));
		if ((child = fork()) == 0)
		{
			execve(argv[1], arg, envp);
			if (errno != 0)
				printf("%s", strerror(errno));
		}
		else
			wait(NULL);
	}
	return (0);
}
