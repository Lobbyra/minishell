/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:46:58 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/10 14:00:29 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int  cast_input_files(char *command, int fd_dst)
{
	char	*path;

	while (*command && ft_strncmp(command, " < ", 3) != 0)
		command++;
	if (ft_strncmp(command, " < ", 3) == 0)
		command += 3;
	while (*command)
	{
		if (!(path = ft_get_this_word(command)))
			return (ERR_MALLOC);
		ft_fdcaster(open(path, O_RDONLY), fd_dst);
		while (*command && ft_strncmp(command, " < ", 3) != 0)
			command++;
		if (ft_strncmp(command, " < ", 3) == 0)
			command += 3;
	}
	return (0);
}

int			cast_redir(t_stock *s, t_exec *e)
{
	int error;

	/*
	if (e->is_pipe == TRUE && e->is_piped == TRUE)
	{
		if (dup2(s->fds_pipe[1], STDOUT) == -1)
			return (ERR_ERRNO);
		ft_fdcaster(s->fds_pipe[0], STDIN);
	}
	if (e->is_pipe == TRUE && e->is_piped == FALSE)
		if (dup2(s->fds_pipe[1], STDOUT) == -1)
 			return (ERR_ERRNO);
	if (e->is_pipe == FALSE && e->is_piped == TRUE)
		ft_fdcaster(s->fds_pipe[0], STDIN);
	*/
	if (e->is_filein_redir == TRUE)
	{
		if ((error = cast_input_files(s->command, STDIN)) != 0)
			return (error);
		char *argv[3] = {"tail", "-n", "2"};
		execve("/usr/bin/tail", argv, NULL);
	}
	exit (0);
}
