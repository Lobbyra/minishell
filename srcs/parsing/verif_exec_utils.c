/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_exec_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:45:58 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/07/17 16:17:27 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_builtins(char *jobs)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(jobs);
	if (ft_strncmp(jobs, "export", len) == 0)
		return (1);
	if (ft_strncmp(jobs, "unset", len) == 0)
		return (1);
	if (ft_strncmp(jobs, "exit", len) == 0)
		return (1);
	return (0);
}

static int	free_alloc(char *exec, char **path, char *jobs)
{
	free(exec);
	free(jobs);
	ft_strarrfree(path);
	return (0);
}

static int	check_all_path(t_stock *s, int n, t_bool is_debug)
{
	int			i;
	int			status;
	char		*exec;
	char		*tmp;
	char		**path;
	struct stat	buf;

	i = 0;
	status = 0;
	if (is_metacharacter(s->jobs[n][0][0]))
	{
		exec = ft_strjoin("/", s->jobs[n][2]);
		status = 1;
	}
	else
		exec = ft_strjoin("/", s->jobs[n][0]);
	path = get_path(s->envp);
	if (path == NULL)
		return (-1);
	while (path[i])
	{
		tmp = ft_strjoin(path[i], exec);
		errno = 0;
		stat(tmp, &buf);
		if (errno == 0)
		{
			if (status == 0)
			{
				free_alloc(exec, path, s->jobs[n][0]);
				s->jobs[n][0] = tmp;
			}
			else
			{
				free_alloc(exec, path, s->jobs[n][2]);
				s->jobs[n][2] = tmp;
			}
			if (is_debug == TRUE)
				l_printf("exec: %s\n", tmp);
			return (1);
		}
		free(tmp);
		i++;
	}
	free(exec);
	ft_strarrfree(path);
	return (0);
}

int			management_check_all_path(t_stock *s, int n, t_bool is_debug)
{
	if (check_all_path(s, n, is_debug) == 1)
		return (1);
	if (is_builtins(s->jobs[n][0]))
		return (1);
	return (0);
}
