/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:44:44 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/24 18:00:50 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	### CUT_CMD ###
**	This function is only used in ft_wait_instruction. it return the cmd less
**	first command and free cmd. If cmd contain only one command, it return null.
*/

/*
**	### IS_COMMAND_NEXT ###
**	This function will check if cmd at i contain a cmd.
*/

static char		*return_creator(char *cmd, int i)
{
	char *tmp;

	if (cmd[i] != ';')
	{
		free(cmd);
		return (NULL);
	}
	else
		i++;
	if (cmd[pass_spaces(cmd, i)] == '\0')
	{
		free(cmd);
		return (NULL);
	}
	tmp = ft_strdup(cmd + i);
	free(cmd);
	return (tmp);
}

char			*cut_cmd(char *cmd)
{
	int		i;

	i = 0;
	if (!cmd)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] == '\"' && is_escaped(cmd, i) == FALSE)
			i = pass_dquote(cmd, i);
		else if (cmd[i] == '\'' && is_escaped(cmd, i) == FALSE)
			i = pass_quote(cmd, i);
		else if (cmd[i] == ';' && is_escaped(cmd, i) == FALSE)
		{
			break ;
		}
		else
			i++;
	}
	return (return_creator(cmd, i));
}
