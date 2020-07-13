/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_escaped.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:19:36 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/13 14:39:22 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function check if the char at i is escaped or not.
**	If it is, this function return TRUE. FALSE else.
*/

#include "minishell.h"

t_bool	is_escaped(char *cmd, int i)
{
	int n_backslash_saw;

	n_backslash_saw = 0;
	if (i > ft_strlen(cmd) || i < 0)
		return (FALSE);
	while (i - n_backslash_saw - 1 >= 0 && cmd[i - n_backslash_saw - 1] == '\\')
		n_backslash_saw++;
	if (n_backslash_saw % 2 == 1)
		return (TRUE);
	return (FALSE);
}
