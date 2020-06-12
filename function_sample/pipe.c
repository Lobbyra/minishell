#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <strings.h>

int			l_strlen(char *str)
{
	char *temp;

	temp = str;
	while (*temp)
		temp++;
	return (temp - str);
}

void		l_putstr_fd(char *s, int fd)
{
	write(fd, s, l_strlen(s));
}

int		main()
{
	int		p1[2];
	pid_t	child;
	char	buf[500];

	pipe(p1);
	child = fork();
	if (child == 0)
	{
		read(p1[0], buf, 500);
		l_putstr_fd(buf, 1);
	}
	else
	{
		l_putstr_fd("Coucou je suis bien passé !", p1[1]);
		wait(NULL);
	}
	return (0);
}
