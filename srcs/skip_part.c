/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:21:40 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/24 18:00:27 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			is_special_c(char *c)
{
	if (*c == '|' || *c == '<')
		return (*c == '|' || *c == '<');
	else if (ft_strncmp(c, ">>", 2) == 0)
		return ((ft_strncmp(c, ">>", 2) == 0));
	return (*c == '>');
}

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

int			skip_part(char **cmd)
{
	char	quote;
	char	*save_cmd;

	quote = **cmd;
	save_cmd = *cmd;
	if (quote == '\'')
		skip_part_quote(cmd);
	else if (quote == '\"')
		skip_part_dquote(cmd);
	else if (is_special_c(&quote))
		(*cmd)++;
	else
	{
		while (**cmd)
		{
			if ((**cmd == ' ' || **cmd == '\'' || **cmd == '\"'
			|| is_special_c(*cmd))
			&& *(*cmd - 1) != '\\')
				break ;
			(*cmd)++;
		}
	}
	return (*cmd - save_cmd);
}
