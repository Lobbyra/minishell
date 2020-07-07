/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:50:52 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/07 17:04:54 by jecaudal         ###   ########.fr       */
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

static int	word_counter(char *user_input)
{
	int count;

	count = 0;
	while (*user_input)
	{
		ft_skip(&user_input, ' ');
		if (is_special_c(user_input))
		{
			user_input++;
			count++;
		}
		else if (*user_input)
		{
			while (*user_input != '\0' && *user_input != ' '
			&& !is_special_c(user_input))
				skip_part(&user_input);
			count++;
		}
	}
	return (count);
}

static void	special_management(char ***i_new, char **cmd)
{
	free(**i_new);
	**i_new = ft_ctostr(**cmd);
	(*i_new)++;
	(*cmd)++;
}

char		**split_command(char *cmd)
{
	char **new;
	char **i_new;

	if (!(new = init_split(word_counter(cmd))))
		return (NULL);
	i_new = new;
	while (*cmd)
	{
		ft_skip(&cmd, ' ');
		if (is_special_c(cmd))
			special_management(&i_new, &cmd);
		else
		{
			while (*cmd && *cmd != ' ' && !is_special_c(cmd))
			{
				if (!(*i_new = part_add(*i_new, cmd, part_len(cmd, *cmd))))
					return (panic_split_command(new, i_new));
				skip_part(&cmd);
			}
			i_new++;
		}
	}
	if ((new = join_outpend(new)) == NULL)
		return (NULL);
	return (new);
}
