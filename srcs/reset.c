/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:32:01 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/06 13:35:18 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_jobs(char ***jobs)
{
	char ***save_jobs;

	save_jobs = jobs;
	while (*jobs)
	{
		ft_freestrs(*jobs);
		*jobs = NULL;
		jobs++;
	}
	free(save_jobs);
}

void		reset(t_stock *stock)
{
	if (stock->jobs)
	{
		free_jobs(stock->jobs);
		stock->jobs = NULL;
	}
	if (stock->pipes)
	{
		free(stock->pipes);
		stock->pipes = NULL;
	}
	if (stock->error_strings)
	{
		free(stock->error_strings);
		stock->error_strings = NULL;
	}
	if (stock->user_input)
	{
		free(stock->user_input);
		stock->user_input = NULL;
	}
}
