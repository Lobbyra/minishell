/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoted_meta_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 13:47:58 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/07 15:40:32 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The source code in this file its dedicated for the single quoted meta-char.
*/

#include "minishell.h"

/*
**	### FOR IS_SINGLE_QUOTED_META() ###
**
**	arg var is the buffer to add many chained quoted strings.
**	So if this string is empty, we are sure there isn't char before and meta
**	can be single.
**
**	cmd is the iteration of the user_input.
*/

t_bool		is_single_quoted_meta(char *arg, char *cmd)
{
	char	quote;

	quote = *cmd;
	if (ft_strcmp(arg, "") != 0)
		return (FALSE);
	if (quote != '\'' && quote != '\"')
		return (FALSE);
	if (is_special_c(cmd + 1) == FALSE)
		return (FALSE);
	if (ft_strncmp(cmd + 1, ">>", 2) == 0)
		cmd += 3;
	else
		cmd += 2;
	if (*cmd == quote)
		return (TRUE);
	return (FALSE);
}

char	*single_meta_quoted(char *arg, char *cmd)
{
	int		size;
	char	*new;

	size = 3;
	if (ft_strncmp(cmd + 1, ">>", 2) == 0)
		size = 4;
	if (!(new = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memcpy_n(new, cmd, size);
	new[size] = '\0';
	if (arg)
		free(arg);
	return (new);
}

char	*single_quoted_remover(char *arg)
{
	int		size;
	char	*new;

	size = 1;
	if (ft_strncmp(arg + 1, ">>", 2) == 0)
		size = 2;
	if (!(new = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (size == 2)
		ft_memcpy_n(new, ">>", 2);
	else
		*new = arg[1];
	new[size] = '\0';
	if (arg)
		free(arg);
	return (new);
}
