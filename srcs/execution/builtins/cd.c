/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 13:53:35 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/24 17:58:03 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This is the source code of cd builtins. Here cd will not options or more
**	than one path.
*/

#include "minishell.h"

static char		*get_home(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp("HOME=", *envp, 5) == 0)
			return (ft_strdup((*envp) + 5));
		envp++;
	}
	return (NULL);
}

static int		home_not_set(void)
{
	ft_putstr_fd("minishell: cd: HOME not set\n", STDERR);
	return (1);
}

static t_bool	is_home_in_envp(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp("HOME=", *envp, 5) == 0)
			return (TRUE);
		envp++;
	}
	return (FALSE);
}

int				cd(char *path, char **envp)
{
	char	*home;

	errno = 0;
	if (path == NULL)
	{
		if (is_home_in_envp(envp) == FALSE)
			return (home_not_set());
		home = get_home(envp);
		chdir(home);
		free(home);
	}
	else
		chdir(path);
	if (errno != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	return (0);
}
