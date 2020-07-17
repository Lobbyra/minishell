/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:46:51 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/16 18:46:20 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function return the index to the char after spaces. If there is no
**	spaces, reuturn i
*/

#include "minishell.h"

int		pass_spaces(char *ui, int i)
{
	while (ui[i] == ' ')
		i++;
	return (i);
}
