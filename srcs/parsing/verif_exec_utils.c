/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_exec_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:45:58 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/07/22 17:06:22 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_builtins(char *jobs)
{
	int		len;

	len = ft_strlen(jobs);
	if (ft_strncmp(jobs, "export", len) == 0)
		return (1);
	if (ft_strncmp(jobs, "unset", len) == 0)
		return (1);
	if (ft_strncmp(jobs, "exit", len) == 0)
		return (1);
	return (0);
}

int			free_alloc(char *exec, char **path, char *jobs)
{
	free(exec);
	free(jobs);
	ft_strarrfree(path);
	return (0);
}

int			check_all_path_utils(char **jobs, char **path, char *exec,
int status)
{
	int			i;
	char		*tmp;
	struct stat	buf;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], exec);
		errno = 0;
		stat(tmp, &buf);
		if (errno == 0)
		{
			if (status == 0)
				free_get_path_exec_one(path, exec, jobs, tmp);
			else
				free_get_path_exec_two(path, exec, jobs, tmp);
			return (1);
		}
		free(tmp);
		i++;
	}
	return (0);
}

static int	check_all_path(t_stock *s, int n)
{
	int			status;
	char		*exec;
	char		**path;

	status = 0;
	if (is_metacharacter(s->jobs[n][0][0]))
	{
		exec = NULL;
		if ((check_exec_after_redirection(s, n, &status, exec)) == 0)
			return (0);
	}
	else
		exec = ft_strjoin("/", s->jobs[n][0]);
	path = get_path(s->envp);
	if (path == NULL)
		return (-1);
	if ((check_all_path_utils(s->jobs[n], path, exec, status)) == 1)
		return (1);
	free(exec);
	ft_strarrfree(path);
	return (0);
}

int			management_check_all_path(t_stock *s, int n)
{
	if (check_all_path(s, n) == 1)
		return (1);
	if (is_builtins(s->jobs[n][0]))
		return (1);
	return (0);
}
