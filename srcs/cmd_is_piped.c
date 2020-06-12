/*
** Created by Jérémy Caudal on 22/04/2020.
*/

#include "minishell.h"

t_bool	cmd_is_piped(char *user_input)
{
	while (*user_input && *user_input != ';' && *user_input != '\n')
	{
		if (*user_input == '|')
			return (TRUE);
		user_input++;
	}
	return (FALSE);
}