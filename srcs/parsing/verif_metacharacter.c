/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_metacharacter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:15:46 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/07/21 14:27:38 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function check if there is two metacharacters followed with nothing
**	between.
*/

#include "minishell.h"

int				is_metacharacter(char c)
{
	if (c == '>' || c == '<')
		return (1);
	return (0);
}

int				verif_metacharacter(t_stock *s, char **cmd)
{
	int i;

	i = 0;
	while (cmd[i] && cmd[i + 1])
	{
		if (is_metacharacter(cmd[i][0]) && is_metacharacter(cmd[i + 1][0]))
		{
			s->error_strings = ft_strjoindel(s->error_strings, \
			"minishell: syntax error near unexpected token `", 1);
			s->error_strings = ft_strjoindel(s->error_strings, \
			ft_strjoin(cmd[i + 1], "'\n"), 3);
			return (0);
		}
		if (is_metacharacter(cmd[i][0]) && cmd[i + 1][0] == '|')
		{
			s->error_strings = ft_strjoindel(s->error_strings, ERR_PIPE2, 1);
			return (0);
		}
		i++;
	}
	return (1);
}
