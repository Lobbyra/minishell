#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int		main(int argc, char **argv)
{
	struct stat buf;
	if (argc == 2)
	{
		errno = 0;
		stat(argv[1], &buf);
		if (errno != 0)
			printf("Error : %s\n", strerror(errno));
		else
		{
			printf("UID of owner is %d.\n", buf.st_uid);
			printf("This file weigh %lld bytes.\n", buf.st_size);
			printf("This path points a ");
			if ((buf.st_mode & S_IFMT) == S_IFREG) 
				printf("file.\n");
			else if ((buf.st_mode & S_IFMT) == S_IFLNK) 
				printf("symlink.\n");
			else if ((buf.st_mode & S_IFMT) == S_IFDIR) 
				printf("directory.\n");
			printf("You have ");
			if (!(buf.st_mode & S_IRUSR) &&
				!(buf.st_mode & S_IWUSR) &&
				!(buf.st_mode & S_IXUSR))
				printf("no ");
			if (buf.st_mode & S_IRUSR)
				printf("read ");
			if (buf.st_mode & S_IWUSR)
				printf("write ");
			if (buf.st_mode & S_IXUSR)
				printf("execution ");
			printf("rights on this.\n");
		}
	}
	else
		printf("USAGE : lstat [path]\n");
	return (0);
}
