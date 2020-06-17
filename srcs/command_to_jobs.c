/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_to_jobs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:04:08 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/17 16:18:50 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	This function Transform the user instruction to an array to arrays of
**	stringsin stock->jobs. This char*** isn't ended by null cause we put to null
**	commands are not correctly. So we put the number of commands in
**	stock->n_jobs.
**	Return ERR_MALLOC or 0.
*/

static int	panic_split_jobs(char ***jobs, int ptrs_alloced)
{
	int i;

	i = 0;
	while (i < ptrs_alloced)
	{
		free(jobs[i]);
		i++;
	}
	return (ERR_MALLOC);
}

static int	job_len(char **words)
{
	int i;

	i = 0;
	if (!words)
		return (0);
	while (*words)
	{
		if (ft_strcmp(*words, "|") == 0)
			break ;
		i++;
		words++;
	}
	return (i);
}

static int	split_jobs(char ***jobs, int n_jobs, char **words)
{
	int i;
	int j;

	i = 0;
	if (!jobs || !words)
		return (-1);
	while (i < n_jobs)
	{
		j = 0;
		if (!(jobs[i] = (char**)malloc(sizeof(char*) * (job_len(words) + 1))))
			return (panic_split_jobs(jobs, i));
		while (ft_strcmp(*words, "|") != 0 && *words)
		{
			jobs[i][j++] = ft_strdup(*words);
			words++;
		}
		if (ft_strcmp(*words, "|") == 0)
			words++;
		jobs[i][j] = NULL;
		i++;
	}
	return (0);
}

static int	jobs_counter(char **words)
{
	int i;

	i = 1;
	if (!words)
		return (0);
	while (*words)
	{
		if (ft_strcmp(*words, "|") == 0)
			i++;
		words++;
	}
	return (i);
}

int			command_to_jobs(t_stock *stock, char *cmd)
{
	char **splitter;

	if (!(cmd = ft_strcleaner(cmd)))
		return (ERR_MALLOC);
	if (!(splitter = ft_split(cmd, " ")))
		return (ERR_MALLOC);
	stock->n_jobs = jobs_counter(splitter);
	if (!(stock->jobs = (char***)malloc(sizeof(char**) * (stock->n_jobs))))
	{
		ft_freestrs(splitter);
		return (ERR_MALLOC);
	}
	if (split_jobs(stock->jobs, stock->n_jobs, splitter) != 0)
	{
		ft_freestrs(splitter);
		return (ERR_MALLOC);		
	}
	return (0);
}