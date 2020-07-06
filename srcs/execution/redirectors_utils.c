/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirectors_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 14:05:40 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/06 13:30:37 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool		is_out_redir(char **job)
{
	while (*job)
	{
		if (ft_strcmp(*job, ">") == 0 || ft_strcmp(*job, ">>") == 0)
			return (TRUE);
		job++;
	}
	return (FALSE);
}

t_bool		is_in_redir(char **job)
{
	while (*job)
	{
		if (ft_strcmp(*job, "<") == 0)
			return (TRUE);
		job++;
	}
	return (FALSE);
}

static int	len_less_redir(char **job)
{
	int count;

	count = 0;
	while (*job)
	{
		if (ft_strcmp(*job, ">") == 0 ||
			ft_strcmp(*job, ">>") == 0 ||
			ft_strcmp(*job, "<") == 0)
			job += 2;
		else
		{
			count++;
			job++;
		}
	}
	return (count);
}

char		**rm_redir(char **job)
{
	char	**new;
	char	**i_new;
	char	**save_job;

	save_job = job;
	if (!(new = (char**)malloc(sizeof(char*) * (len_less_redir(job) + 1))))
		return (NULL);
	i_new = new;
	*(new + len_less_redir(job)) = NULL;
	while (*job)
	{
		if (ft_strcmp(*job, ">") == 0 ||
			ft_strcmp(*job, ">>") == 0 ||
			ft_strcmp(*job, "<") == 0)
			job += 2;
		else
		{
			*i_new = ft_strdup(*job);
			job++;
			i_new++;
		}
	}
	ft_freestrs(save_job);
	return (new);
}
