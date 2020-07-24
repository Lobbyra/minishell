/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance_builder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:42:41 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/24 17:55:02 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	### INSTANCE_BUILDER ###
**	This function will create the child and do redirections within it.
*/

/*
**	### IS_ABORTED ###
**	This function check in the list_exec_abort if the current job will have to
**	don't execute specified binary.
*/

t_bool	is_aborted(t_stock *s, int jobpos)
{
	int i;

	i = 0;
	if (s->list_exec_abort == NULL)
		return (FALSE);
	while (i < s->size_list && jobpos <= s->list_exec_abort[i])
	{
		if (jobpos == s->list_exec_abort[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_child	init_child(t_stock *s, int jobpos, int *pipes, t_bool is_pipe)
{
	t_child	new;
	char	**tmp;

	new.job = s->jobs[jobpos];
	tmp = find_exec(new.job);
	new.is_aborted = FALSE;
	if (tmp == NULL)
	{
		new.is_aborted = TRUE;
		new.path = ft_strdup("");
	}
	else
		new.path = arg_cleaner(ft_strdup(*tmp));
	new.exec_name = ft_basename(new.path);
	new.args = ft_strarrdup(new.job);
	new.args = rm_redir(new.args);
	job_cleaner(new.args);
	new.jobpos = jobpos;
	new.pipes = pipes;
	new.is_pipe = is_pipe;
	new.is_aborted += is_aborted(s, jobpos);
	new.s = s;
	return (new);
}

void	child_process(t_child c)
{
	int err;

	err = 0;
	err = redirector(c.pipes, c.jobpos, c.is_pipe, c.s);
	close_pipes(c.pipes, (c.s->n_jobs * 2) - 2);
	if (err != 0)
		exit(1);
	if (c.is_aborted == FALSE && is_builtin(c.path) == TRUE)
		builtin_call_child(c.args, &(c.s->exit_status), &(c.s->envp));
	else if (c.is_aborted == FALSE && c.s->is_exec_abort == FALSE &&
		(!ft_c_finder('/', c.path) || execve(c.path, c.job, c.s->envp) == -1))
		print_exec_err(c.path);
	exit(1);
}

int		instance_builder(t_stock *s, int jobpos, int *pipes, t_bool is_pipe)
{
	t_child child;

	child = init_child(s, jobpos, pipes, is_pipe);
	if (s->is_debug == TRUE)
		debug_child(child);
	if ((child.pid = fork()) == 0)
	{
		child_process(child);
	}
	else if (child.pid == -1)
		return (panic_ib(child));
	free_child(child);
	return (0);
}
