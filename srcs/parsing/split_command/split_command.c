/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:50:52 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/23 16:36:55 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	#### CHAR **SPLIT_COMMAND() ####
**	Vocabulary :
**		- Command :	Is the full stdin from the user.
**		- Arg : 	Is each words seperate by spaces.
**		- Part :	A part is a sequence quoted or non-quoted seperate by the
**					start, the end or quoted sequence. example :
**					hey"world"'wassup' = {hey, "world", 'wassup'}
**	
**	Description :
**	This function will split each argument from the cmd less quotes and
**	backslash when it's necessary.
*/

#include "minishell.h"

static char	**panic_split_command(char **new, char **i_new)
{
	while (i_new > new)
	{
		if (*i_new)
			free(*i_new);
		i_new--;
	}
	if (new)
		free(new);
	return (NULL);
}

char		**split_command(char *cmd)
{
	char **new;
	char **i_new;
	
	if (!(new = (char**)init_split(sizeof(char*) *
		(word_counter(cmd) + 1))))
		return (NULL);
	i_new = new;
	while (*cmd)
	{
		ft_skip(&cmd, ' ');
		if (*cmd)
		{
			while (*cmd && *cmd != ' ')
			{
				// printf("\nin split_command : cmd = [%s]; part_len = %d\n", cmd, part_len(cmd, *cmd));
				// fflush(stdout);
				*i_new = part_add(*i_new, cmd, part_len(cmd, *cmd));
				if (!(*i_new))
					return (panic_split_command(new, i_new));
				skip_part(&cmd);
			}
			i_new++;
		}
	}
	*i_new = NULL;
	return (new);
}

/*
int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("[%s] splitted = [", argv[1]);
		fflush(stdout);
		ft_putarrstr(split_command(argv[1]), "], [");
		printf("]\n");
	}	
	return (0);
}
*/