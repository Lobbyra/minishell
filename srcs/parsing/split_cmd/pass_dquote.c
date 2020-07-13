/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_dquote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:49:25 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/13 16:50:14 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function return the char after the double quoted char serie.
*/

#include "minishell.h"

int		pass_dquote(char *ui, int i)
{
	i++;
	while (ui[i])
	{
		if (ui[i] == '\"' && is_escaped(ui, i) == FALSE)
			break ;
		i++;
	}
	if (ui[i] == '\"')
		i++;
	return (i);
}
