/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 13:48:01 by jereligi          #+#    #+#             */
/*   Updated: 2020/06/19 13:48:54 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int      is_escape(int i, char *user_input)
{
	if (i > 0)
	{
		if (user_input[i - 1] == '\\')
			return (1);
	}
	return (0);
}

static int      additional_read(char quote, char **user_input)
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
			*user_input = ft_strjoindel(*user_input, tmp, 3);
		else if (status == GNL_CTRLD)
			return (ERR_SYNTAX);
	}
	else
		return (1);
	l_printf("|%s|\n", *user_input);
	return (0);
}

int             check_quote(char *user_input)
{
	int		i;
	int		valid_quote;
	char	quote;

	i = 0;
	valid_quote = 0;
	quote = '0';
	while (valid_quote == 0)
	{
		if (user_input[i] == '\0')
			if ((valid_quote = additional_read(quote, &user_input)) == 3)
				return (ERR_SYNTAX);
		if ((user_input[i] == '"' && quote == '0') && (!is_escape(i, user_input)))
			quote = '\"';
		else if ((user_input[i] == '\'' && quote == '0') && (!is_escape(i, user_input)))
			quote = '\'';
		else if ((quote == user_input[i]) && (!is_escape(i, user_input)))
			quote = '0';
		i++;
	}
	return (0);
}