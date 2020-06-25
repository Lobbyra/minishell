/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:21:40 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/24 17:58:09 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	skip_part_quote(char **cmd)
{
	(*cmd)++;
	while (**cmd)
	{
		if (**cmd == '\'')
			break ;
		(*cmd)++;
	}
	if (**cmd == '\'')
		(*cmd)++;
}

static void	skip_part_dquote(char **cmd)
{
	(*cmd)++;
	while (**cmd)
	{
		if (**cmd == '\"' && *(*cmd - 1) != '\\')
			break ;
		(*cmd)++;
	}
	if (**cmd == '\"')
		(*cmd)++;
}

void	skip_part(char **cmd)
{
	char quote;

	quote = **cmd;
	if (quote == '\'')
		skip_part_quote(cmd);
	else if (quote == '\"')
		skip_part_dquote(cmd);
	else if (quote == '|')
		(*cmd)++;
	else
	{
		while (**cmd)
		{
			if ((**cmd == ' ' || **cmd == '\'' || **cmd == '\"' || **cmd == '|')
			&&	*(*cmd - 1) != '\\')
				break ;
			(*cmd)++;
		}
	}
}
