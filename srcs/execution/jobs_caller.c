/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_caller.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:24:06 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/15 18:18:23 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function will calling functions to run jobs by jobs.
*/

#include "minishell.h"

static void	debug_jobs_caller(t_stock *stock, int *pipes)
{
	l_printf("### DEBUG JOBS_CALLER ###\n");
	ft_putarrarrstrs(stock->jobs, stock->n_jobs);
	l_printf("pipes = ");
	ft_putnbrarr_fd(pipes, stock->n_jobs * 2 - 2, 1);
	write(1, "\n", 1);
	l_printf("stock->n_jobs = %d\n", stock->n_jobs);
	l_printf("###___________________###\n\n");
}

int			jobs_caller(t_stock *s)
{
	int		err;
	int		*pipes;
	t_bool	is_pipe;
	char	***i_jobs;

	i_jobs = s->jobs;
	if ((err = init_pipes(&pipes, s->n_jobs)) && err != 0)
		return (err);
	if (s->is_debug == TRUE)
		debug_jobs_caller(s, pipes);
	while (i_jobs - s->jobs < s->n_jobs)
	{
		if (*i_jobs && **i_jobs)
		{
			is_pipe = (s->n_jobs > 1 && i_jobs - s->jobs < s->n_jobs - 1);
			instance_builder(s, i_jobs - s->jobs, pipes, is_pipe);
		}
		i_jobs++;
	}
	close_pipes(pipes, (s->n_jobs - 1) * 2);
	if (pipes)
		free(pipes);
	return (0);
}
