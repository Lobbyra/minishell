/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:36:34 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/22 16:45:13 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			panic_wait_instruction(char **to_free, int err)
{
	if (*to_free != NULL)
	{
		free(*to_free);
		*to_free = NULL;
	}
	return (err);
}

/*
**	Will return a duplication of cmd without the first command.
*/

static char	*cut_cmd(char *cmd)
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
		else if (cmd[i] == '\'' && is_escaped(cmd, i) == FALSE)
			i = pass_quote(cmd, i);
		else if (cmd[i] == ';' && is_escaped(cmd, i) == FALSE)
		{
			break ;
		}
		else
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

char		*get_cmd(char *user_input)
{
	int		i;
	char	*new;

	i = 0;
	while (user_input[i])
	{
		if (user_input[i] == '\"' && is_escaped(user_input, i) == FALSE)
			i = pass_dquote(user_input, i);
		else if (user_input[i] == '\'' && is_escaped(user_input, i) == FALSE)
			i = pass_quote(user_input, i);
		else if (user_input[i] == ';' && is_escaped(user_input, i) == FALSE)
		{
			break ;
		}
		else
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

static int	read_ui(t_stock *s)
{
	char	*pwd;
	int		status;

	pwd = NULL;
	if (s->buf_user_input == NULL)
	{
		pwd = getcwd(NULL, MAX_PATH_LEN);
		if (g_is_ctrlc == FALSE)
			l_printf("\033[32mminishell\033[37m[%s]$>", pwd);
		status = get_next_line(0, &(s->buf_user_input));
		if (status == -1)
			return (panic_wait_instruction(&(s->buf_user_input), ERR_ERRNO));
		if (status == 2)
			return (1);
		status = check_user_input(s->buf_user_input, &s->exit_status);
		if (status != 0)
			return (panic_wait_instruction(&(s->buf_user_input), status));
	}
	if (pwd != NULL)
		free(pwd);
	g_is_ctrlc = FALSE;
	return (0);
}

int			wait_instruction(t_stock *s)
{
	int err;

	if ((err = read_ui(s)) != 0)
		return (err);
	s->is_cmd_closed = is_cmd_closed(s->buf_user_input);
	if ((err = check_quote(s)) != 0)
	{
		if (s->is_debug == TRUE)
			l_printf("\033[32mcheck quote [ok]\033[37m\n");
		return (ERR_CRITIC);
	}
	if ((err = check_pipe(s)) != 0)
	{
		if (s->is_debug == TRUE)
			l_printf("\033[32mcheck pipe [ok]\033[37m\n");
		return (ERR_CRITIC);
	}
	s->user_input = get_cmd(s->buf_user_input);
	s->buf_user_input = cut_cmd(s->buf_user_input);
	return (0);
}
