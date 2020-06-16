/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_to_jobs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:04:08 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/16 14:09:13 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	This function Transform the user instruction to an array to arrays of
**	stringsin stock->jobs. This char*** isn't ended by null cause we put to null
**	commands are not correctly. So we put the number of commands in
**	stock->n_jobs.
**	Return ERR_MALLOC or 0.
*/
int		command_to_jobs(t_stock *stock, char *cmd)
{
	return (0);
}