#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/errno.h>

#define FT_PATH_MAXLEN 4096

int		main()
{
	char	argv[100];
	char	option[100];
	char	*workdir;

	if (!(workdir = (char*)malloc(sizeof(char) * FT_PATH_MAXLEN + 1)))
		return (1);
	getcwd(workdir, FT_PATH_MAXLEN);
	while (strcmp(argv, "exit") != 0)
	{
		errno = 0;
		scanf("%s", argv);
		getcwd(workdir, FT_PATH_MAXLEN);
		if (strcmp(argv, "pwd") == 0)
			printf("%s\n", workdir);
		else if (strcmp(argv, "cd") == 0)
		{
			scanf("%s", option);
			chdir(option);
			if (errno != 0)
				printf("%s\n", strerror(errno));
		}
	}
	return (0);
}
