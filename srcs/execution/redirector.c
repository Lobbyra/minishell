/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:30:00 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/02 16:26:09 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function will dup2 correctly I/O need to be duped accord to command and
**	which command is to pipe or not. It manage also file redirection.
*/

#include "minishell.h"

static void	debug_redirector(int jobpos, t_bool is_pipe)
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

int			redirector(int *pipes, int jobpos, t_bool is_pipe, t_stock *s)
{
	int err;

	err = 0;
	if (is_out_redir(s->jobs[jobpos]) == TRUE)
		err = redirector_file_out(s, jobpos);
	else
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
		if (s->is_debug == TRUE)
			debug_redirector(jobpos, is_pipe);
	}
	s->jobs[jobpos] = rm_redir(s->jobs[jobpos]);
	return (err);
}