/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_len_nquote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:49:51 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/14 16:24:52 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function return the len of the non-quoted part until the end of the
**	string of the start of a new part. This is the len with escaper characters.
*/

#include "minishell.h"

int		part_len_nquote(char *arg, int i)
{
	int i_temp;

	i_temp = i;
	while (arg[i_temp])
	{
		if ((arg[i_temp] == '\'' || arg[i_temp] == '\"') &&
			is_escaped(arg, i_temp) == FALSE)
			break ;
		i_temp++;
	}
	return (i_temp - i);
}
