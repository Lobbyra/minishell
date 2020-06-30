/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:02:43 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/30 17:43:35 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function is the main function of execution part. It take the structure
**	parsed and full, and it will execute and call builtins command.
*/

#include "minishell.h"

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
		err = builtin_caller(s->jobs[0], &s->exit_status, 1, &(s->envp));
		if (err != 0)
			return (err);
	}
	else if ((err = jobs_caller(s)) != 0)
		return (err);
	terminator(s->jobs, s->n_jobs, &(s->exit_status));
	return (0);
}