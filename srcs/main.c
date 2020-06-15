/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:47:17 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/15 16:30:48 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Used to free variables alloced for just one command.
*/
static void	reset_t_stock(t_stock *stock)
{
	int i_jobs;

	i_jobs = 0;
	if (i_jobs)
	{
		while (i_jobs < stock->n_jobs)
			ft_freestrs(stock->jobs[i_jobs++]);
		free(i_jobs);
	}
	if (stock->pipes)
		free(stock->pipes);
	if (stock->error_strings)
		free(stock->error_strings);
}

static char		*wait_instruction(void)
{
	char	*instruction;

	if (get_next_line(0, &instruction) == -1)
		return (NULL);
	return (instruction);
}

int			main(int argc, char **argv, char **envp)
{
	int		error;
	t_stock	*stock;
	char	*command;	

	if (!(stock = init_stock(envp)))
		return (1);
	while (1)
	{
		if (!(command = wait_instruction()) && (error = ERR_MALLOC))
			error_printer(ERR_MALLOC_MSG);
		if (ft_strcmp(command, "") == 0)
			break ;
	}
	free_t_stock(stock);
	return (0);
}