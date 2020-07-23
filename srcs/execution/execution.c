/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:02:43 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/23 18:45:23 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function is the main function of execution part. It take the structure
**	parsed and full, and it will execute and call builtins command.
*/

#include "minishell.h"

static void	debug_jobs(char ***jobs, int size)
{
	l_printf("### DEBUG JOBS ###\n");
	l_printf("Your jobs :\n");
	ft_putarrarrstrs(jobs, size);
	l_printf("###____________###\n\n");
}

int			execution(t_stock *s)
{
	int		err;
	int		save_stdout;
	char	**exec;

	err = 0;
	if (s->is_debug == TRUE)
		debug_jobs(s->jobs, s->n_jobs);
	exec = find_exec(s->jobs[0]);
	if (s->n_jobs == 1 && exec && is_builtin(*exec) == TRUE)
	{
		save_stdout = dup(1);
		if (is_out_redir(s->jobs[0]) == TRUE)
			err = redirector_file_out(s, 0);
		s->jobs[0] = rm_redir(s->jobs[0]);
		job_cleaner(s->jobs[0]);
		if (err == 0 && is_aborted(s, 0) == FALSE && s->is_exec_abort == FALSE)
			builtin_call_parent(s->jobs[0], &s->exit_status, 1, &(s->envp));
		dup2(save_stdout, 1);
		close(save_stdout);
	}
	else if ((err = jobs_caller(s)) != 0)
		return (err);
	terminator(s->jobs, s->n_jobs, &(s->exit_status));
	return (0);
}
