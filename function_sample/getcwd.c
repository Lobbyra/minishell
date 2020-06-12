#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define FT_MAX_PATH_LEN 4096

int		main()
{
	char *str;

	if (!(str = (char*)malloc(sizeof(char) * FT_MAX_PATH_LEN + 1)))
		return (1);
	getcwd(str, FT_MAX_PATH_LEN);
	printf("Your current dir is %s.", str);
	free(str);
	return (0);
}
