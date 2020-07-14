/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_len_dquote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:49:52 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/14 16:24:26 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function return the len of the quoted string at index.
**	It count until the end of the string of the end of the quoted string.
**	int i must be at be at delimiter double quote.
*/

#include "minishell.h"

int		part_len_dquote(char *arg, int i)
{
	int i_temp;

	i_temp = i + 1;
	while (arg[i_temp])
	{
		if (arg[i_temp] == '\"' && is_escaped(arg, i_temp) == FALSE)
			break ;
		i_temp++;
	}
	return (i_temp - i + 1);
}
