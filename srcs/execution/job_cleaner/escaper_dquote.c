/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escaper_dquote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:49:57 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/14 17:26:47 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function will edit buf string to remove escape char when 
**	'$' or '\' or '"' is escaped.
*/

#include "minishell.h"

int		escaper_dquote(char *buf)
{
	char	*copy;
	int		i_buf;
	int		i_copy;

	i_buf = 0;
	i_copy = 0;
	if (!(copy = ft_strdup(buf)))
		return (ERR_MALLOC);
	while (copy[i_copy])
	{
		if (copy[i_copy] == '\\' && is_escaped(copy, i_copy) == FALSE &&
			(copy[i_copy + 1] == '\"' || copy[i_copy + 1] == '$' ||
			 copy[i_copy + 1] == '\\'))
			i_copy++;
		if (copy[i_copy])
			buf[i_buf++] = copy[i_copy++];
	}
	while (buf[i_buf])
		buf[i_buf++] = '\0';
	free(copy);
	return (0);
}
