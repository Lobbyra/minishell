/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_caller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:18:48 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/22 17:53:11 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_call_parent(char **job, int *ex, int fd, char ***envp)
{
	char *exec_name;

	exec_name = ft_basename(*job);
	if (ft_strcmp(exec_name, "cd") == 0)
		*ex = cd(*(find_exec(job) + 1), *envp);
	else if (ft_strcmp(exec_name, "echo") == 0)
		*ex = echo(job, fd);
	else if (ft_strcmp(exec_name, "env") == 0)
		*ex = env(job, *envp, fd);
	else if (ft_strcmp(exec_name, "export") == 0)
		*ex = export(envp, job, fd);
	else if (ft_strcmp(exec_name, "exit") == 0)
		ft_exit(find_exec(job));
	else if (ft_strcmp(exec_name, "pwd") == 0)
		*ex = pwd(fd);
	else if (ft_strcmp(exec_name, "unset") == 0)
		*ex = unset(envp, job);
	free(exec_name);
}

void	builtin_call_child(char **job, int *exit_stat, char ***envp)
{
	char *exec_name;

	exec_name = ft_basename(*job);
	if (ft_strcmp(exec_name, "cd") == 0)
		*exit_stat = cd(*(find_exec(job) + 1), *envp);
	else if (ft_strcmp(exec_name, "echo") == 0)
		*exit_stat = echo(job, 1);
	else if (ft_strcmp(exec_name, "env") == 0)
		*exit_stat = env(job, *envp, 1);
	else if (ft_strcmp(exec_name, "export") == 0)
		*exit_stat = export(envp, job, 1);
	else if (ft_strcmp(exec_name, "exit") == 0)
		ft_exit(find_exec(job));
	else if (ft_strcmp(exec_name, "pwd") == 0)
		*exit_stat = pwd(1);
	else if (ft_strcmp(exec_name, "unset") == 0)
		*exit_stat = unset(envp, job);
	free(exec_name);
	exit(*exit_stat);
}
