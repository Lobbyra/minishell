/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_to_jobs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:32:53 by jereligi          #+#    #+#             */
/*   Updated: 2020/06/24 18:37:10 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		number_jobs(char **command)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (command[i])
	{
		if (command[i][0] == '|')
			len++;
		i++;
	}
	return (len);
}

static int		jobs_len(char ***jobs, char **command)
{
	int	i;
	int	n;
	int	len;

	i = 0;
	n = 0;
	len = 0;
	while (command[i])
	{
		if (command[i][0] == '|' || command[i + 1] == '\0')
			len = i;
		if (len != 0)
		{
			if (!(jobs[n] = (char **)malloc(sizeof(char *) * len + 1)))
				return (-1);
			jobs[n][len] = NULL;
			n++;
			len = 0;
		}
		i++;
	}
	return (0);
}

static int		insert_data_jobs(char ***jobs, char **command)
{
	int		i;
	int		n;
	int		x;

	i = 0;
	n = 0;
	x = 0;
	while (command[i])
	{
		if (command[i][0] == '|')
		{
			n++;
			x = 0;
		}
		else
		{
			jobs[n][x] = ft_strdup(command[i]);
			x++;
		}
		i++;
	}
	return (0);
}

int				command_to_jobs(t_stock *s, char **command)
{
	int		len;
	char	***jobs;

	len = number_jobs(command);
	if (!(jobs = (char ***)malloc(sizeof(char **) * len + 1)))
		return (-1);
	jobs[len + 1] = NULL;
	jobs_len(jobs, command);
	insert_data_jobs(jobs, command);
	// s->jobs = jobs;
	int	n, x, i;
	n = 0;
	while (jobs[n])
	{
		x = 0;
		while (jobs[n][x])
		{
			l_printf("jobss[%d][%d] : %s\n", n, x, jobs[n][x]);
			x++;
		}
		n++;
	}
	i = 0;
	while (command[i])
		free(command[i++]);
	free(command);
	i = 0;
	while (jobs[i])
	{
		n = 0;
		while (jobs[i][n])
		{
			free(jobs[i][n++]);
		}
		i++;
	}
	i = 0;
	while (jobs[i])
		free(jobs[i++]);
	free(jobs);
	return (0);
}
