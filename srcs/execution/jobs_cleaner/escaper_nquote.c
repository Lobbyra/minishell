/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escaper_nquote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:49:55 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/14 17:31:01 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function will edit buf to remove all escape backslash in the string.
*/

#include "minishell.h"

int		escaper_nquote(char *buf)
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
		if (copy[i_copy] == '\\' && is_escaped(copy, i_copy) == FALSE)
			i_copy++;
		if (copy[i_copy])
			buf[i_buf++] = copy[i_copy++];
	}
	while (buf[i_buf])
		buf[i_buf++] = '\0';
	free(copy);
	return (0);
}
