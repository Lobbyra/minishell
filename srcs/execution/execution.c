/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:02:43 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/29 18:49:37 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	debug_execution(t_stock *stock, int *pipes)
{
	ft_putarrarrstrs(stock->jobs, stock->n_jobs);
	ft_putnbrarr_fd(pipes, stock->n_jobs * 2 - 2, 1);
	l_printf("stock->n_jobs = %d\n", stock->n_jobs);
}

static int	jobs_caller(t_stock *s)
{
	int err;
	int *pipes;
	char	***i_jobs;

	i_jobs = s->jobs;
	if ((err = init_pipes(&pipes, s->n_jobs)) && err != 0)
		return (err);
	if (s->is_debug == TRUE)
		debug_execution(s, pipes);
	while (i_jobs - s->jobs < s->n_jobs)
	{
		if (**i_jobs)
		{
			if (s->n_jobs > 1 && i_jobs - s->jobs > s->n_jobs - 1)
				s->is_pipe = TRUE;
			else
				s->is_pipe = FALSE;
			instance_builder(s, i_jobs - s->jobs, pipes);
		}
		i_jobs++;
	}
	return (0);
}

static t_bool	is_builtin(char *path)
{
	t_bool	ret;
	char	*exec_name;
	
	ret = FALSE;
	if (!(exec_name = ft_basename(path)))
		return (FALSE);
	if (ft_strcmp(exec_name, "cd") == 0)
		ret = TRUE;
	else if (ft_strcmp(exec_name, "echo") == 0)
		ret = TRUE;
	else if (ft_strcmp(exec_name, "env") == 0)
		ret = TRUE;
	else if (ft_strcmp(exec_name, "export") == 0)
		ret = TRUE;
	else if (ft_strcmp(exec_name, "exit") == 0)
		ret = TRUE;
	else if (ft_strcmp(exec_name, "pwd") == 0)
		ret = TRUE;
	else if (ft_strcmp(exec_name, "unset") == 0)
		ret = TRUE;
	free(exec_name);
	return (ret);
}

int		execution(t_stock *s)
{
	int		err;

	if (s->n_jobs == 1 && is_builtin(s->jobs[0][0]) == TRUE)
	{
		if (
		(err = builtin_caller(s->jobs[0], &s->exit_status, 1, &(s->envp))
			) != 0)
			return (err);
	}
	else if ((err = jobs_caller(s)) != 0)
		return (err);
	terminator(s->jobs, s->n_jobs, &(s->exit_status));
	return (0);
}