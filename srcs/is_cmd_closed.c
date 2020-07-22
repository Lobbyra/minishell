/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:15:26 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/22 14:52:07 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This command return true if there is at least one ';' command separator char
**	in the user_input.
*/

#include "minishell.h"

t_bool	is_cmd_closed(char *ui)
{
	int		i;

	i = 0;
	if (!ui)
		return (FALSE);
	while (ui[i])
	{
		if (ui[i] == '\"' && is_escaped(ui, i) == FALSE)
			i = pass_dquote(ui, i);
		else if (ui[i] == '\'' && is_escaped(ui, i) == FALSE)
			i = pass_quote(ui, i);
		else if (ui[i] == ';' && is_escaped(ui, i) == FALSE)
		{
			break ;
		}
		else
			i++;
	}
	if (ui[i] == ';')
		return (TRUE);
	return (FALSE);
}
