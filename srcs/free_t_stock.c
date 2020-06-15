/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_stock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:19:36 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/15 15:28:05 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_jobs(char ***jobs, int n_jobs)
{
	int i;

	i = 0;
	while (i < n_jobs)
	{
		ft_freestrs(jobs[i]);
		i++;
	}
}

void	free_t_stock(t_stock *stock)
{
	if (stock->envp)
		ft_freestrs(stock->envp);
	if (stock->jobs)
		free_jobs(stock->jobs, stock->n_jobs);
	if (stock->pipes)
		free(stock->pipes);
	if (stock->error_strings)
		free(stock->error_strings);
}