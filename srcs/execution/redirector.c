/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:30:00 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/30 17:55:51 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function will dup2 correctly I/O need to be duped accord to command and
**	which command is to pipe or not. It manage also file redirection.
*/

#include "minishell.h"

static void	debug_redirector(int *pipes, int jobpos, t_bool is_pipe)
{
	l_printf("### DEBUG REDIRECTOR ###\n");
	l_printf("is_pipe = %d\n", is_pipe);
	l_printf("jobpos = %d\n", jobpos);
	if (jobpos == 0 && is_pipe == TRUE)
		l_printf("STDOUT redirected.\n\n");
	else if (jobpos > 0 && is_pipe == TRUE)
		l_printf("STDIN & STDOUT redirected.\n\n");
	else if (jobpos > 0 && is_pipe == FALSE)
		l_printf("STDIN redirected.\n\n");
}

void		redirector(int *pipes, int jobpos, t_bool is_pipe, t_bool is_debug)
{
	if (jobpos == 0 && is_pipe == TRUE)
		dup2(pipes[(jobpos * 2) + 1], STDOUT);
	else if (jobpos > 0 && is_pipe == TRUE)
	{
		dup2(pipes[(jobpos * 2) + 1], STDOUT);
		dup2(pipes[(jobpos * 2) - 2], STDIN);
	}
	else if (jobpos > 0 && is_pipe == FALSE)
		dup2(pipes[(jobpos * 2) - 2], STDIN);
	if (is_debug == TRUE)
		debug_redirector(pipes, jobpos, is_pipe);
}