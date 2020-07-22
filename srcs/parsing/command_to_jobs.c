/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_to_jobs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:32:53 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/22 15:05:02 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		number_jobs(char **command)
{
	int	i;
	int	len;

	i = 0;
	if (!command[i])
		return (0);
	len = 1;
	while (command[i])
	{
		if (command[i][0] == '|')
			len++;
		i++;
	}
	return (len);
}

static int		job_alloc(char ***jobs, int *n, int *len, int *status)
{
	if (!(jobs[*n] = (char **)malloc(sizeof(char *) * (*len + 1))))
		return (-1);
	jobs[*n][*len - 1] = NULL;
	jobs[*n][*len] = NULL;
	*n = *n + 1;
	*len = -1;
	*status = 0;
	return (0);
}

static int		jobs_alloc(char ***jobs, char **command)
{
	int	i;
	int	n;
	int	len;
	int	status;

	i = 0;
	n = 0;
	len = 0;
	status = 0;
	while (command[i])
	{
		if (command[i][0] == '|' || command[i + 1] == '\0')
		{
			status = 1;
			if (nopipe(command) == 0 || command[i + 1] == '\0')
				len++;
		}
		if (status != 0)
			job_alloc(jobs, &n, &len, &status);
		len++;
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
	int		i;
	int		len;
	char	***jobs;

	len = number_jobs(command);
	if (!(jobs = (char ***)malloc(sizeof(char **) * (len + 1))))
		return (-1);
	jobs[len - 1] = NULL;
	jobs[len] = NULL;
	jobs_alloc(jobs, command);
	insert_data_jobs(jobs, command);
	s->jobs = jobs;
	i = 0;
	while (jobs[i])
		i++;
	s->n_jobs = i;
	i = 0;
	while (command[i])
		free(command[i++]);
	free(command);
	return (0);
}
