/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 13:51:24 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/23 14:03:10 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_isprint(char c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}

static int		additional_read_pipe(t_stock *s)
{
	int		status;
	char	*tmp;

	status = 0;
	tmp = NULL;
	l_printf("pipe> ");
	status = get_next_line(0, &tmp);
	if (status == GNL_LINE_READED || status == GNL_EOF)
		s->buf_user_input = ft_strjoindel(s->buf_user_input, tmp, 3);
	else if (status == GNL_CTRLD)
	{
		s->error_strings = ft_strjoindel(s->error_strings, ERR_PIPE1, 1);
		return (ERR_CRITIC);
	}
	if (s->is_debug == TRUE)
		l_printf("|%s|\n", s->buf_user_input);
	return (check_quote(s));
}

int				check_pipe_utils(t_stock *s, int *i)
{
	(*i)++;
	while (ft_isprint(s->buf_user_input[*i]) == 0 && s->buf_user_input[*i])
		(*i)++;
	if ((s->buf_user_input[*i] == '\0' || s->is_cmd_closed == TRUE) &&
	s->buf_user_input[*i] == ';')
	{
		s->error_strings = ft_strjoindel(s->error_strings, ERR_PIPE3, 1);
		s->is_exec_abort = TRUE;
		return (ERR_CRITIC);
	}
	else if (s->buf_user_input[*i] == '\0')
	{
		if (additional_read_pipe(s) == ERR_CRITIC)
			return (ERR_CRITIC);
		*i = 0;
	}
	return (0);
}

int				check_pipe(t_stock *s)
{
	int i;
	int valid_pipe;

	i = 0;
	valid_pipe = 0;
	while (valid_pipe == 0)
	{
		if (s->buf_user_input[i] == '\0')
			valid_pipe = 1;
		if (i == 0 && s->buf_user_input[i] == '|')
		{
			s->error_strings = ft_strjoindel(s->error_strings, ERR_PIPE2, 1);
			return (ERR_SYNTAX);
		}
		else if (s->buf_user_input[i] == '|' &&
		s->buf_user_input[i - 1] != '\\')
			return (check_pipe_utils(s, &i));
		i++;
	}
	return (0);
}
