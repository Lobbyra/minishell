/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 18:03:21 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/24 17:49:45 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This is the builtin source code of echo.
*/

#include "minishell.h"

static int		errno_exit(void)
{
	l_printf("minishell: echo: %s\n", strerror(errno));
	return (1);
}

static int		protected_putarrstr_fd(char **argv, char *sep, int fd)
{
	if (argv && fd > 0)
	{
		while (*argv && *(argv + 1))
		{
			if (write(fd, *argv, ft_strlen(*argv)) == -1 ||
				write(fd, sep, ft_strlen(sep)) == -1)
				return (errno_exit());
			argv++;
		}
		if (*argv)
		{
			if (write(fd, *argv, ft_strlen(*argv)) == -1)
				return (errno_exit());
		}
	}
	return (0);
}

static t_bool	is_option(char *arg)
{
	if (arg && *arg == '-')
	{
		arg++;
		while (*arg == 'n')
			arg++;
	}
	if (arg && *arg == '\0')
		return (TRUE);
	return (FALSE);
}

static int		n_options(char **job)
{
	int count;

	job += 1;
	count = 0;
	while (job && is_option(*job) == TRUE)
	{
		job++;
		count++;
	}
	return (count);
}

int				echo(char **job, int fd)
{
	errno = 0;
	if (ft_strarrlen(job) > 1)
	{
		if (ft_strncmp(job[1], "-n", 2) == 0)
		{
			if (protected_putarrstr_fd(job + 1 + n_options(job), " ", fd) > 0)
				return (1);
		}
		else
		{
			if (protected_putarrstr_fd(job + 1, " ", fd) > 0)
				return (1);
			if (write(1, "\n", fd) == -1)
				return (errno_exit());
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
