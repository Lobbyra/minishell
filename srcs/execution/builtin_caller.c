/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_caller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:18:48 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/29 18:47:24 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_caller(char **job, char *exit_status, int fd, char ***envp)
{
	char *exec_name;

	if (!(exec_name = ft_basename(*job)))
		return (ERR_MALLOC);
	if (ft_strcmp(exec_name, "cd") == 0)
		*exit_status = cd(job[1]);
	else if (ft_strcmp(exec_name, "echo") == 0)
		*exit_status = echo(job, fd);
	else if (ft_strcmp(exec_name, "env") == 0)
		*exit_status = env(envp, fd);
	else if (ft_strcmp(exec_name, "export") == 0)
		*exit_status = export(envp, job, fd);
	else if (ft_strcmp(exec_name, "exit") == 0)
		ft_exit(ft_atoi(job[1]));
	else if (ft_strcmp(exec_name, "pwd") == 0)
		*exit_status = pwd(fd);
	else if (ft_strcmp(exec_name, "unset") == 0)
		*exit_status = unset(envp, job);
	free(exec_name);
	return (0);
}