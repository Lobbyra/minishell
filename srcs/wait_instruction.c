/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:36:34 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/08 15:20:29 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Will return a duplication of cmd without the first command.
*/

static char	*cut_cmd(char *cmd)
{
	char	*ret;
	char	*save_cmd;

	save_cmd = cmd;
	while (*cmd)
	{
		if (((*cmd == '\"' || *cmd == '\'') && cmd == save_cmd) ||
			((*cmd == '\"' || *cmd == '\'') && *(cmd - 1) != '\\'))
			skip_part(&cmd);
		else if ((*cmd == ';' && cmd == save_cmd) ||
			(*cmd == ';' && *(cmd - 1) != '\\'))
			break ;
		else
			cmd++;
	}
	if (*cmd == ';')
		ret = ft_strdup(cmd + 1);
	else
		ret = NULL;
	free(save_cmd);
	return (ret);
}

/*
**	Return the len of the first command in str.
*/

static int	len_first_cmd(char *str)
{
	char *i_str;

	i_str = str;
	while (*i_str)
	{
		if (((*i_str == '\"' || *i_str == '\'') && i_str == str) ||
			((*i_str == '\"' || *i_str == '\'') && *(i_str - 1) != '\\'))
			skip_part(&i_str);
		else if ((*i_str == ';' && i_str == str) ||
			(*i_str == ';' && *(i_str - 1) != '\\'))
			break ;
		else
			i_str++;
	}
	return (i_str - str);
}

static void	pass_n_cpy(char **i_str, char **i_new)
{
	int skipped;

	skipped = skip_part(i_str);
	ft_memcpy_n(*i_new, *(i_str) - skipped, skipped);
	skip_part(i_new);
}

/*
**	This function will return a copy of the first command in str.
**	Commands are separated by non-quoted char ';'.
*/

static char	*get_cmd(char *str)
{
	char	*new;
	char	*i_new;
	char	*i_str;

	i_str = str;
	if (!(new = (char*)malloc(sizeof(char) * (len_first_cmd(str) + 1))))
		return (NULL);
	i_new = new;
	while (*i_str)
	{
		if (((*i_str == '\"' || *i_str == '\'') && i_str == str) ||
			((*i_str == '\"' || *i_str == '\'') && *(i_str - 1) != '\\'))
			pass_n_cpy(&i_str, &i_new);
		else if ((*i_str == ';' && i_str == str) ||
				(*i_str == ';' && *(i_str - 1) != '\\'))
			break ;
		else
		{
			*i_new = *i_str;
			i_str++;
			i_new++;
		}
	}
	new[len_first_cmd(str)] = '\0';
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
	if (pwd != NULL)
		free(pwd);
	g_is_ctrlc = FALSE;
	return (0);
}
