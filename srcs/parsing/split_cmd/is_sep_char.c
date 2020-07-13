/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sep_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:02:38 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/13 18:05:38 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function will return TRUE if the char at index is a separator char.
*/

#include "minishell.h"

t_bool	is_sep_char(char *cmd, int i)
{
	if ((cmd[i] == '|' || cmd[i] == '>' || cmd[i] == '<' || cmd[i] == ' ' ||
		ft_strncmp(cmd + i, ">>", 2) == 0) && is_escaped(cmd, i) == FALSE)
		return (TRUE);
	return (FALSE);
}
