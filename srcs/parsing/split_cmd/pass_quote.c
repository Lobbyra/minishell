/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:48:22 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/13 16:49:20 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function return the index to the char after the quoted word.
*/

#include "minishell.h"

int		pass_quote(char *ui, int i)
{
	i++;
	while (ui[i] && ui[i] != '\'')
		i++;
	if (ui[i] == '\'')
		i++;
	return (i);
}
