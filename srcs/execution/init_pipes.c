/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:41:42 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/30 17:43:11 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function will create a array of int that contain all pipes will be
**	needed by piping redirection.
**	You can find an illustration of this system here :
**	https://urlz.fr/dnNk
*/

#include "minishell.h"

static int	panic_init_pipes(int *new)
{
	free(new);
	return (ERR_MALLOC);
}

int			init_pipes(int **pipes, int n_jobs)
{
	int i;
	int n_pipes;

	i = 0;
	n_pipes = (n_jobs - 1) * 2;
	if (!(*pipes = (int*)malloc(sizeof(int) * (n_pipes))))
		return (ERR_MALLOC);
	while (i / 2 < n_jobs - 1)
	{
		pipe((*pipes) + i);
		i += 2;
	}
	return (0);
}