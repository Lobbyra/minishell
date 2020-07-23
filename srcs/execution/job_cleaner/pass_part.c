/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:49:40 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/14 18:46:38 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pass_part_dquote(char *arg, int *i)
{
	(*i)++;
	while (arg[*i])
	{
		if (arg[*i] == '\"' && is_escaped(arg, *i) == FALSE)
			break ;
		(*i)++;
	}
	if (arg[*i] == '\"')
		(*i)++;
}

static void	pass_part_quote(char *arg, int *i)
{
	(*i)++;
	while (arg[*i])
	{
		if (arg[*i] == '\'')
			break ;
		(*i)++;
	}
	if (arg[*i] == '\'')
		(*i)++;
}

void		pass_part(char *arg, int *i)
{
	if (arg[*i] == '\'')
		pass_part_quote(arg, i);
	else if (arg[*i] == '\"')
		pass_part_dquote(arg, i);
	else
	{
		while (arg[*i])
		{
			if ((arg[*i] == '\'' || arg[*i] == '\"') &&
				is_escaped(arg, *i) == FALSE)
				break ;
			(*i)++;
		}
	}
}
