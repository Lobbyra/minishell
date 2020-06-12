//
// Created by Jérémy Caudal on 30/04/2020.
//

#include "minishell.h"

static int	*panic_file_open(char *path, int *new)
{
	if (path)
		free(path);
	if (new)
		free(new);
	printf("");
	return (NULL);
}

int 		*file_opener(char *command, int n_out_files)
{
	int 	i;
	int 	*new;
	char	*path;

	i = 0;
	if (!(new = (int*)malloc(sizeof(int) * (n_out_files))))
	    return (NULL);
	while (i < n_out_files)
	{
		while ((*command != '>' || !ft_strncmp(command, ">>", 2)) && *command)
			command++;
		command += 2;
		if (!(path = ft_get_this_word(command)))
			return (panic_file_open(path, new));
		if (*command == '>')
		{
			if ((new[i] = open(path, O_WRONLY | O_CREAT, 420)) == 1)
				return (panic_file_open(path, new));
		}
		else
			if ((new[i] = open(path, O_WRONLY | O_APPEND | O_CREAT, 420)) == 1)
				return (panic_file_open(path, new));
		free(path);
		i++;
	}
	return (new);
}

static int	len_less_redir(char **argv)
{
	int		count;

	count = 0;
	if (!argv)
		return (0);
	while (*argv)
	{
		while ((ft_strcmp(*argv, ">") == 0 || ft_strcmp(*argv, ">>") == 0 ||
			ft_strcmp(*argv, "<") == 0) && *argv)
			argv += 2;
		count++;
		if (*argv)
			argv++;
	}
	return (count);
}

char 		**redirection_rm(char **argv)
{
	char	**new;
	char 	**i_new;
	char 	**i_argv;

	if (!(new = (char**)malloc(sizeof(char*) * (len_less_redir(argv) + 1))))
		return (NULL);
	i_new = new;
	i_argv = argv;
	while (*i_argv)
	{
		while ((ft_strcmp(*i_argv, ">") == 0 || ft_strcmp(*i_argv, ">>") == 0 ||
			ft_strcmp(*i_argv, "<") == 0) && *i_argv)
			i_argv += 2;
		*i_new = ft_strdup(*i_argv);
		i_new++;
		if (*i_argv)
			i_argv++;
	}
	*i_new = NULL;
	ft_freestrs(argv);
	return (new);
}
