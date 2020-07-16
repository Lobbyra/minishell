/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector_file_in.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:04:07 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/16 14:47:42 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_errno_path(char *path)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	write(1, "\n", 1);
	return (ERR_ERRNO);
}

static int	print_errno(void)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	write(1, "\n", 1);
	return (ERR_ERRNO);
}

static int	process_redir(int fd, char *path)
{
	int		err;
	char	buf[4096];
	int		pipe_in[2];

	if (fd == -1)
		return (print_errno_path(path));
	if (pipe(pipe_in) == -1)
		return (print_errno());
	while ((err = read(fd, buf, 4095)) > 0)
	{
		buf[err] = '\0';
		write(pipe_in[1], buf, err);
	}
	close(pipe_in[1]);
	if (dup2(pipe_in[0], STDIN) == -1)
		return (print_errno());
	close(pipe_in[0]);
	return (0);
}

int			redirector_file_in(char **job)
{
	int		fd;
	char	*path;

	while (*job)
	{
		errno = 0;
		if (ft_strcmp(*job, "<") == 0)
		{
			if (ft_strcmp(*job, "<") == 0)
				fd = open(*(job + 1), O_RDONLY);
			path = *(job + 1);
			l_printf("Debug redirector_file_in path = [%s]\n", path);
			if (fd == -1)
				break ;
			job += 2;
		}
		else
			job++;
	}
	return (process_redir(fd, path));
}
