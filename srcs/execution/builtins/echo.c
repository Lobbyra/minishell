/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 18:03:21 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/23 18:37:53 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This is the builtin source code of echo.
*/

#include "minishell.h"

static int	protected_putarrstr_fd(char **argv, char *sep, int fd)
{
	if (argv && fd > 0)
	{
		while (*(argv + 1))
		{
			if (write(fd, *argv, ft_strlen(*argv)) == -1 ||
				write(fd, sep, ft_strlen(sep)) == -1)
				return (errno);
			argv++;
		}
		if (*argv)
		{
			if (write(fd, *argv, ft_strlen(*argv)) == -1)
				return (errno);
		}
	}
	return (0);
}

int			echo(char **job, int fd)
{
	if (ft_strarrlen(job) > 1)
	{
		if (ft_strcmp(job[1], "-n") == 0)
		{
			if (protected_putarrstr_fd(job + 2, " ", fd) > 0)
				return (1);
		}
		else
		{
			if (protected_putarrstr_fd(job + 1, " ", fd) > 0)
				return (1);
			if (write(1, "\n", fd) == -1)
				return (errno);
		}
	}
	return (0);	
}

/*
int		main(int argc, char **argv)
{
	if (argc > 1)
		printf("echo = %d\n", echo(argv + 1, 1));
	return (0);
}
*/