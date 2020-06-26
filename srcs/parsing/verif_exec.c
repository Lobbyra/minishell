/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:08:03 by jereligi          #+#    #+#             */
/*   Updated: 2020/06/26 18:02:10 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_builtins(char *jobs)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(jobs);
	if (ft_strncmp(jobs, "export", len) == 0)
		return (1);
	if (ft_strncmp(jobs, "unset", len) == 0)
		return (1);
	return (0);
}

char		*ft_pwd(void)
{
	char *str;

	if (!(str = (char*)malloc(sizeof(char) * 4028 + 1)))
		return (NULL);
	getcwd(str, 4028);
	return (str);
}

static int	check_all_path(t_stock *s, int n)
{
	int			i;
	char		*exec;
	char		*tmp;
	char		**path;
	struct stat	buf;

	i = 0;
	exec = ft_strjoin("/", s->jobs[n][0]);
	path = get_path(s->envp);
	while (path[i])
	{
		tmp = ft_strjoin(path[i], exec);
		errno = 0;
		stat(tmp, &buf);
		if (errno == 0)
		{
			free(exec);
			free(path);
			free(s->jobs[n][0]);
			l_printf("exec: %s", tmp);
			s->jobs[n][0] = tmp;
			return (1);
		}
		free(tmp);
		i++;
	}
	if (is_builtins(s->jobs[n][0]))
		return (1);
	ft_strjoindel(s->error_strings, \
	ft_strjoin("minishell: command not found: ", s->jobs[n][0]), 2);
	l_printf("error path: %s\n", s->jobs[n][0]);
	s->jobs[n][0] = NULL;
	return (0);
}

static int	check_path(t_stock *s, int i)
{
	struct stat	buf;

	stat(s->jobs[i][0], &buf);
	if (errno != 0)
	{
		ft_strjoindel(s->error_strings, \
		ft_strjoin("minishell: no such file or directory: ", s->jobs[i][0]), 2);
		l_printf("error path: %s\n", s->jobs[i][0]);
		s->jobs[i][0] = NULL;
		return (1);
	}
	return (0);
}

static int	check_is_slash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '/')
			return (1);
		else if (str[i] == '/')
			return (2);
		i++;
	}
	return (0);
}

int			verif_exec(t_stock *s)
{
	int i;
	int	status;

	i = 0;
	status = 0;
	while (s->jobs[i])
	{
		status = check_is_slash(s->jobs[i][0]);
		if (status == 1)
			check_path(s, i);
		else if (status == 2)
		{
			s->jobs[i][0] = ft_strjoindel(ft_pwd(), \
			ft_strjoindel("/", s->jobs[i][0], 2), 3);
			check_path(s, i);
		}
		else if (status == 0)
			check_all_path(s, i);
		i++;
	}
	return (0);
}
