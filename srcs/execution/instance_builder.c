/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance_builder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:29:13 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/29 17:35:40 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	debug_ib(char *path, char *exec_name)
{
	if (path)
		l_printf("path = %s\n", path);
	if (exec_name)
		l_printf("exec_name = %s\n", exec_name);
}

static int	panic_ib(char *path, char *exec_name, int err)
{
	if (path)
		free(path);
	if (exec_name)
		free(exec_name);
	return (err);
}

int			instance_builder(t_stock *s, int jobpos, int *pipes)
{
	pid_t	child;
	char	*path;
	char	*exec_name;

	errno = 0;
	if (!(path = ft_strdup(s->jobs[jobpos][0])))
		return (ERR_MALLOC);
	if (!(exec_name = ft_basename(s->jobs[jobpos][0])))
		return (panic_ib(path, NULL, ERR_MALLOC));
	if (s->is_debug == TRUE)
		debug_ib(path, exec_name);
	child = fork();
	if (child == 0)
	{
		s->jobs[jobpos][0] = exec_name;
		if (execve(path, s->jobs[jobpos], s->envp) == -1)
			l_printf("minishell: child: %s\n", strerror(errno));
	}
	else if (child == -1)
		return (panic_ib(path, exec_name, ERR_ERRNO));
	return (panic_ib(path, exec_name, 0));
}
