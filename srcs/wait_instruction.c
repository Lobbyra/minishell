/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:36:34 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/15 17:40:40 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Will return a duplication of cmd without the first command.
*/

static char *cut_cmd(char *cmd)
{
	int		i;
	char	*new;

	i = 0;
	if (!cmd)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] == '\"' && is_escaped(cmd, i) == FALSE)
			i = pass_dquote(cmd, i);
		if (cmd[i] == '\'' && is_escaped(cmd, i) == FALSE)
			i = pass_quote(cmd, i);
		if (cmd[i] == ';' && is_escaped(cmd, i) == FALSE)
			break ;
		i++;
	}
	if (cmd[i++] == ';' && !(new = ft_strdup(cmd + i)))
		free(cmd);
	else if (cmd[i - 1] != ';')
		new = NULL;
	free(cmd);
	return (new);
}

/*
**	This function will return a copy of the first command in str.
**	Commands are separated by non-quoted char ';'.
*/

char *get_cmd(char *user_input)
{
	int		i;
	char	*new;

	i = 0;
	while (user_input[i])
	{
		if (user_input[i] == '\"' && is_escaped(user_input, i) == FALSE)
			i = pass_dquote(user_input, i);
		if (user_input[i] == '\'' && is_escaped(user_input, i) == FALSE)
			i = pass_quote(user_input, i);
		if (user_input[i] == ';' && is_escaped(user_input, i) == FALSE)
			break ;
		i++;
	}
	if (!(new = ft_strdup_n(user_input, i)))
	{
		free(user_input);
		return (NULL);
	}
	return (new);
}

extern t_bool g_is_ctrlc;

int			wait_instruction(t_stock *s)
{
	char	*pwd;
	int		status;

	pwd = NULL;
	if (s->buf_user_input == NULL)
	{
		pwd = getcwd(NULL, MAX_PATH_LEN);
		if (g_is_ctrlc == FALSE)
			l_printf("minishell[%s]$>", pwd);
		status = get_next_line(0, &(s->buf_user_input));
		if (status == -1)
			return (panic_wait_instruction(&(s->buf_user_input), ERR_ERRNO));
		if (status == 2)
			return (1);
		if (check_user_input(s->buf_user_input) != 0)
			return (panic_wait_instruction(&(s->buf_user_input), ERR_CMD_VOID));
	}
	s->user_input = get_cmd(s->buf_user_input);
	s->buf_user_input = cut_cmd(s->buf_user_input);
	s->is_cmd_closed = (s->buf_user_input != NULL);
	if (pwd != NULL)
		free(pwd);
	g_is_ctrlc = FALSE;
	return (0);
}
