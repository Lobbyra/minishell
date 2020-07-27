/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_user_input_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:05:40 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/27 13:07:04 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	### CONDITION_TRIGGER ###
**	It's the condition trigger of CHECK_SEMICOLON.
*/

static t_bool	condition_trigger(char *ui, int i)
{
	i++;
	i = pass_spaces(ui, i);
	if (ui[i] == '|')
		return (TRUE);
	return (FALSE);
}

int				check_semicolon_pipe(char *ui)
{
	int i;

	i = 0;
	while (ui[i])
	{
		i = pass_spaces(ui, i);
		if (ui[i] == ';')
		{
			if (condition_trigger(ui, i) == TRUE)
				return (ERR_CRITIC);
			else
				i++;
		}
		else if (is_sep_char(ui, i) == TRUE)
			i++;
		else
			i = pass_word(ui, i);
	}
	return (0);
}
