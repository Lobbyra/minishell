/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_backslash.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:22:41 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/27 14:10:01 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function allows you to check that there is no end backslash error
**	If this is the case, the function rereads the input until the command is
**	valid, otherwise put the error message related to the behavior
*/

#include "minishell.h"

static int		additional_read_backslash(t_stock *s)
{
	int		status;
	char	*tmp;

	status = 0;
	tmp = NULL;
	l_printf("backslash> ");
	status = get_next_line(0, &tmp);
	if (status == GNL_LINE_READED || status == GNL_EOF)
	{
		s->buf_user_input = ft_strdupdel_n(s->buf_user_input,
		ft_strlen(s->buf_user_input) - 1);
		s->buf_user_input = ft_strjoindel(s->buf_user_input, tmp, 3);
	}
	else if (status == GNL_CTRLD)
	{
		tmp = ft_strdup_n(s->buf_user_input, ft_strlen(s->buf_user_input) - 1);
		free(s->buf_user_input);
		s->buf_user_input = tmp;
		return (ERR_EXIT);
	}
	if (s->is_debug == TRUE)
		l_printf("|%s|\n", s->buf_user_input);
	if (check_quote(s) == ERR_CRITIC || check_pipe(s) == ERR_CRITIC)
		return (ERR_CRITIC);
	return (0);
}

int				end_backslash(t_stock *s, int i)
{
	int status;

	status = 0;
	if (s->buf_user_input[i] == '\\' && s->buf_user_input[i - 1] != '\\')
	{
		if (additional_read_backslash(s) == ERR_CRITIC)
			return (ERR_CRITIC);
	}
	else if (s->buf_user_input[i] == '\\' && s->buf_user_input[i - 1] == '\\')
	{
		while (s->buf_user_input[i] == '\\' && s->buf_user_input[i - 1] == '\\')
		{
			if (s->buf_user_input[i] == '\\')
				status++;
			i--;
		}
		if (status % 2 == 0 && additional_read_backslash(s) == ERR_SYNTAX)
			return (ERR_SYNTAX);
	}
	return (0);
}

int				check_end_backslash(t_stock *s)
{
	int		i;
	int		status;

	i = ft_strlen(s->buf_user_input) - 1;
	status = 0;
	if (i > 1)
		return (end_backslash(s, i));
	else
	{
		if (s->buf_user_input[0] == '\\')
			if (additional_read_backslash(s) == ERR_CRITIC)
				return (ERR_CRITIC);
	}
	return (0);
}
