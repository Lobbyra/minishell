/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:37:00 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/04 10:45:08 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	#### STATIC CHAR *PART_ADD() ####
**	Will add current part of cmd to the end of i_new. This function will take
**	care of escape char \.
**	arg : arg that will be completed step by step.
**	cmd : curr ptr to the cmd user typed.
**	p_len :
*/

/*
**	Copy algorithrm for non-quote parts.
*/

static void		cpy_nquote(char **i_new, char *cmd, int p_len)
{
	while (p_len > 0)
	{
		if (*cmd == '\\')
			cmd++;
		**i_new = *cmd;
		*i_new += 1;
		if (*cmd)
			cmd++;
		p_len--;
	}
}

/*
**	Copy algorithm for double quote parts.
*/

static void		cpy_dquote(char **i_new, char *cmd, int p_len)
{
	cmd++;
	while (p_len > 0)
	{
		if (*cmd == '\\' &&
		(*(cmd + 1) == '\"' || *(cmd + 1) == '$' || *(cmd + 1) == '`'))
			cmd++;
		**i_new = *cmd;
		*i_new += 1;
		cmd++;
		p_len--;
	}
}

/*
** Copy algorithm for simple quote parts.
*/

static void		cpy_quote(char **i_new, char *cmd, int p_len)
{
	cmd++;
	while (p_len > 0)
	{
		**i_new = *cmd;
		*i_new += 1;
		cmd++;
		p_len--;
	}
}

char			*part_add(char *arg, char *cmd, int p_len)
{
	char	*new;
	char	*i_new;
	char	quote;

	quote = *cmd;
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(arg) + p_len + 1))))
		return (NULL);
	ft_memcpy_n(new, arg, ft_strlen(arg));
	i_new = new + ft_strlen(arg);
	if (quote != '\'' && quote != '\"')
		cpy_nquote(&i_new, cmd, p_len);
	else if (quote == '\'')
		cpy_quote(&i_new, cmd, p_len);
	else if (quote == '\"')
		cpy_dquote(&i_new, cmd, p_len);
	*i_new = '\0';
	free(arg);
	return (new);
}
