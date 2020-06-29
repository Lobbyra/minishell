/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:44:07 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/29 18:03:32 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function will wait all child process until they are dead.
*/

#include "minishell.h"

static int	count_non_builtins_jobs(char ***jobs, int n_jobs)
{
	int count;
	char ***i_jobs;

	count = 0;
	i_jobs = jobs;
	while (i_jobs - jobs < n_jobs)
	{
		if (**i_jobs)
			count++;
		i_jobs++;
	}
	return (count);
}

void	terminator(char ***jobs, int n_jobs, char *status)
{
	int n_dead;
	int n_childs;

	n_dead = 0;
	n_childs = count_non_builtins_jobs(jobs, n_jobs);
	while (n_dead < n_childs)
	{
		wait((int*)status);
		*status = WEXITSTATUS(*status);
		n_dead++;
	}
}