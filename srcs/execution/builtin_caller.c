/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_caller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:18:48 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/02 13:57:45 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_call_parent(char **job, char *exit_stat, int fd, char ***envp)
{
	char *exec_name;

	exec_name = ft_basename(*job);
	if (ft_strcmp(exec_name, "cd") == 0)
		*exit_stat = cd(*(find_exec(job) + 1));
	else if (ft_strcmp(exec_name, "echo") == 0)
		*exit_stat = echo(job, fd);
	else if (ft_strcmp(exec_name, "env") == 0)
		*exit_stat = env(*envp, fd);
	else if (ft_strcmp(exec_name, "export") == 0)
		*exit_stat = export(envp, job, fd);
	else if (ft_strcmp(exec_name, "exit") == 0)
		ft_exit(ft_atoi(*(find_exec(job) + 1)));
	else if (ft_strcmp(exec_name, "pwd") == 0)
		*exit_stat = pwd(fd);
	else if (ft_strcmp(exec_name, "unset") == 0)
		*exit_stat = unset(envp, job);
	free(exec_name);
}

void	builtin_call_child(char **job, char *exit_stat, char ***envp)
{
	char *exec_name;

	exec_name = ft_basename(*job);
	if (ft_strcmp(exec_name, "cd") == 0)
		*exit_stat = cd(*(find_exec(job) + 1));
	else if (ft_strcmp(exec_name, "echo") == 0)
		*exit_stat = echo(job, 1);
	else if (ft_strcmp(exec_name, "env") == 0)
		*exit_stat = env(*envp, 1);
	else if (ft_strcmp(exec_name, "export") == 0)
		*exit_stat = export(envp, job, 1);
	else if (ft_strcmp(exec_name, "exit") == 0)
		ft_exit(ft_atoi(*(find_exec(job) + 1)));
	else if (ft_strcmp(exec_name, "pwd") == 0)
		*exit_stat = pwd(1);
	else if (ft_strcmp(exec_name, "unset") == 0)
		*exit_stat = unset(envp, job);
	free(exec_name);
	exit(*exit_stat);
}