//
// Created by Jérémy Caudal on 27/04/2020.
//

#include "minishell.h"

t_bool	is_files_in_output(char *command)
{
	while (*command && ft_c_finder(*command, "|\n;") == FALSE)
	{
		if (ft_strncmp(command, " > ", 3) == 0 ||
			ft_strncmp(command, " >> ", 4) == 0)
			return (TRUE);
		command++;
	}
	return (FALSE);
}

t_bool	is_files_in_input(char *command)
{
	while (*command && ft_c_finder(*command, "|\n;") == FALSE)
	{
		if (ft_strncmp(command, " < ", 3) == 0)
			return (TRUE);
		command++;
	}
	return (FALSE);
}

t_bool	is_pipe(char *user_input)
{
	while (*user_input && *user_input != ';' && *user_input != '\n')
	{
		if (*user_input == '|')
			return (TRUE);
		user_input++;
	}
	return (FALSE);
}

int		count_out_files(char *str)
{
	int count;

	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (ft_strncmp(str, " > ", 3) == 0 ||
			ft_strncmp(str, " >> ", 4) == 0)
			count++;
		str++;
	}
	return (count);
}
