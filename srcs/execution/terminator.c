/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:44:07 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/22 16:27:30 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function will wait all child process until they are dead.
*/

#include "minishell.h"

static int	count_non_builtins_jobs(char ***jobs, int n_jobs)
{
	int		count;
	char	***i_jobs;

	count = 0;
	i_jobs = jobs;
	while (i_jobs - jobs < n_jobs)
	{
		if (*i_jobs && **i_jobs)
			count++;
		i_jobs++;
	}
	return (count);
}

void		terminator(char ***jobs, int n_jobs, int *status)
{
	int		n_dead;
	int		n_childs;
	t_bool	is_quit_printed;

	n_dead = 0;
	is_quit_printed = FALSE;
	n_childs = count_non_builtins_jobs(jobs, n_jobs);
	if (n_childs == 1 && *jobs && is_builtin(find_exec(jobs[0])[0]) == TRUE)
		return ;
	while (n_dead < n_childs)
	{
		wait((int*)status);
		if (WIFSIGNALED(*status))
		{
			if (WTERMSIG(*status) == 3 && is_quit_printed == FALSE &&
				(is_quit_printed = TRUE))
				l_printf("\r^\\Quit: 3");
			*status = 128 + WTERMSIG(*status);
		}
		else
			*status = WEXITSTATUS(*status);
		n_dead++;
	}
	if (is_quit_printed == TRUE)
		print_prompt();
}
