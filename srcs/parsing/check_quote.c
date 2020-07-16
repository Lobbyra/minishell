/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:54:35 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/16 17:47:24 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (status == GNL_LINE_READED || status == GNL_EOF)
		{
			tmp = ft_strjoindel("\n", tmp, 2);
			s->user_input = ft_strjoindel(s->user_input, tmp, 3);
		}
		else if (status == GNL_CTRLD)
		{
			s->error_strings = ft_strjoin(ERR_QUOTE1, &quote);
			s->error_strings = ft_strjoindel(s->error_strings, ERR_QUOTE2, 1);
			l_printf("%s\n", s->error_strings);
			return (ERR_SYNTAX);
		}
	}
	else
		return (1);
	return (0);
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
		if (s->user_input[i] == '\0')
			if ((valid_quote = additional_read_quote(quote, s)) == 3)
				return (ERR_SYNTAX);
		if ((s->user_input[i] == '"' && quote == '0')
		&& (!is_escaped(s->user_input, i)))
			quote = '\"';
		else if ((s->user_input[i] == '\'' && quote == '0')
		&& (!is_escaped(s->user_input, i)))
			quote = '\'';
		else if (((quote == s->user_input[i]) && (!is_escaped(s->user_input, i)))
		|| (quote == '\'' && quote == s->user_input[i]
		&& is_escaped(s->user_input, i)))
			quote = '0';
		i++;
	}
	return (0);
}
