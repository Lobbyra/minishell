/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:54:35 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/23 15:55:02 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function allows you to check that there is no quote error
**	If this is the case, the function rereads the input until the command is
**	valid, otherwise put the error message related to the behavior	
*/

#include "minishell.h"

int				is_escape(int i, char *user_input)
{
	if (i > 0)
	{
		if (user_input[i - 1] == '\\')
			return (1);
	}
	return (0);
}

extern t_bool g_is_ctrlc;

static int		additional_read_quote(char quote, t_stock *s)
{
	int		status;
	char	*tmp;

	status = 0;
	tmp = NULL;
	if (quote != '0')
	{
		l_printf("quote> ");
		status = get_next_line(0, &tmp);
		if (g_is_ctrlc == TRUE)
			return (ERR_CRITIC);
		if (status == GNL_LINE_READED || status == GNL_EOF)
		{
			tmp = ft_strjoindel("\n", tmp, 2);
			s->buf_user_input = ft_strjoindel(s->buf_user_input, tmp, 3);
		}
		else if (status == GNL_CTRLD)
		{
			s->error_strings = ft_strjoindel(ERR_QUOTE1, ft_ctostr(quote), 2);
			s->error_strings = ft_strjoindel(s->error_strings, ERR_QUOTE2, 1);
			return (ERR_CRITIC);
		}
	}
	return (1);
}

int				check_quote(t_stock *s)
{
	int		i;
	int		valid_quote;
	char	quote;

	i = 0;
	valid_quote = 0;
	quote = '0';
	while (valid_quote == 0)
	{
		if (s->buf_user_input[i] == '\0')
			if ((valid_quote = additional_read_quote(quote, s)) == ERR_CRITIC)
				return (ERR_CRITIC);
		if ((s->buf_user_input[i] == '"' && quote == '0')
		&& (!is_escaped(s->buf_user_input, i)))
			quote = '\"';
		else if ((s->buf_user_input[i] == '\'' && quote == '0')
		&& (!is_escaped(s->buf_user_input, i)))
			quote = '\'';
		else if (((quote == s->buf_user_input[i]) && (!is_escaped(
		s->buf_user_input, i))) || (quote == '\'' && quote ==
		s->buf_user_input[i] && is_escaped(s->buf_user_input, i)))
			quote = '0';
		i++;
	}
	return (0);
}
