#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int		ft_strlen(char *str)
{
	char	*temp;

	temp = str;
	if (!str)
		return (0);
	while (*temp)
		temp++;
	return (temp - str);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*new;

	i = 0;
	if (!str)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_strarrnuller(char **tab, unsigned int size)
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
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

int		main(int argc, char **argv, char **envp)
{
	char *str = "Input test";
	char **arg = ft_strarrnuller(argv, argc);
	int p1[2];
	
	pipe(p1);
	dup2(p1[0], 0);
	arg[0] = ft_strdup("tail");
	close(p1[1]);
	if (fork() == 0)
	{
		if (execve("/usr/bin/tail", arg, envp) == -1)
			printf("Erreur execve\n");
	}
	wait(NULL);
	return (0);
}
