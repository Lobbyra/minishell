/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_len_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:49:47 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/14 16:41:43 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function will return the len of a quoted part in arg at i.
*/

#include "minishell.h"

int		part_len_quote(char *arg, int i)
{
	int i_temp;

	i_temp = i + 1;
	while (arg[i_temp])
	{
		if (arg[i_temp] == '\'')
			break ;
		i_temp++;
	}
	return (i_temp - i + 1);
}
