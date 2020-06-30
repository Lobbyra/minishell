/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_backslash.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:22:41 by jereligi          #+#    #+#             */
/*   Updated: 2020/06/30 18:09:29 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		tmp = ft_strjoindel("\n", tmp, 2);
		s->user_input = ft_strjoindel(s->user_input, tmp, 3);
	}
	else if (status == GNL_CTRLD)
	{
		tmp = ft_strdup_n(s->user_input, ft_strlen(s->user_input) - 1);
		free(s->user_input);
		s->user_input = tmp;
		return (ERR_EXIT);
	}
	if (s->is_debug == TRUE)
		l_printf("|%s|\n", s->user_input);
	if (check_quote(s) == ERR_SYNTAX || check_pipe(s) == ERR_SYNTAX)
		return (ERR_SYNTAX);
	return (0);
}

int				check_end_backslash(t_stock *s)
{
	int		i;
	int		status;

	i = 0;
	status = 0;
	while (s->user_input[i])
		i++;
	i--;
	if (s->user_input[i] == '\\' && s->user_input[i - 1] != '\\')
	{
		if (additional_read_backslash(s) == ERR_SYNTAX)
			return (ERR_SYNTAX);
	}
	else if (s->user_input[i] == '\\' && s->user_input[i - 1] == '\\')
	{
		while (s->user_input[i] == '\\' && s->user_input[i - 1] == '\\')
		{
			if (s->user_input[i] == '\\')
				status++;
			i--;
		}
		if (status % 2 == 0)
			if (additional_read_backslash(s) == ERR_SYNTAX)
				return (ERR_SYNTAX);
	}
	return (0);
}
