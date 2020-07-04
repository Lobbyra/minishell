/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector_file_out.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 14:13:03 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/04 11:39:38 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	process_redir(int fd, char *path)
{
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		write(1, "\n", 1);
		return (ERR_ERRNO);
	}
	else if (dup2(fd, STDOUT) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		write(1, "\n", 1);
		return (ERR_ERRNO);
	}
	close(fd);
	return (0);
}

int			redirector_file_out(t_stock *s, int jobpos)
{
	int		fd;
	char	**i_job;

	i_job = s->jobs[jobpos];
	while (*i_job)
	{
		errno = 0;
		if (ft_strcmp(*i_job, ">") == 0 || ft_strcmp(*i_job, ">>") == 0)
		{
			if (ft_strcmp(*i_job, ">") == 0)
				fd = open(*(i_job + 1), O_WRONLY | O_TRUNC | O_CREAT, 420);
			else
				fd = open(*(i_job + 1), O_WRONLY | O_APPEND | O_CREAT, 420);
			if (fd == -1)
				break ;
			i_job += 2;
		}
		else
			i_job++;
	}
	return (process_redir(fd, *(i_job + 1)));
}
