#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	int 		fd;
	struct stat buf;

	if (argc == 2)
	{
		errno = 0;
		fd = open(argv[1], O_RDONLY);
		if (errno != 0)
		{
			printf("Error : %s\n", strerror(errno));
			exit(1);
		}
		fstat(fd, &buf);
		if (errno != 0)
		{
			printf("Error : %s\n", strerror(errno));
			exit(1);
		}
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
		close(fd);
	}
	else
		printf("USAGE : lstat [path]\n");
	return (0);
}
