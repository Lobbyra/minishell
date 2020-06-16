/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:47:17 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/16 14:59:59 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Used to free variables alloced for just one command.
*/
static void	reset(t_stock *stock, char *command)
{
	int i_jobs;

	i_jobs = 0;
	if (i_jobs)
	{
		while (i_jobs < stock->n_jobs)
			ft_freestrs(stock->jobs[i_jobs++]);
		free(stock->jobs);
	}
	if (stock->pipes)
		free(stock->pipes);
	if (stock->error_strings)
		free(stock->error_strings);
	if (command)
		free(command);
}

static int	wait_instruction(char **instruction)
{
	int error;

	error = get_next_line(0, instruction);
	if (error == -1)
		return (ERR_MALLOC);
	if (error == GNL_CTRLD)
		return (GNL_CTRLD);
	return (0);
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
		error = 0;
		if ((error = get_next_line(0, &command)) == -1)
			error_printer(error);
		if (error == GNL_CTRLD)
			break ;
		if (error == 0 && (error = command_to_jobs(stock, command)))
			error_printer(error);
		if (error == 0 && (error = parsing(stock)) != 0)
			error_printer(error);
		if (error == 0 && (error = execution(stock)) != 0)
			error_printer(error);
		reset(stock, command);
	}
	free_t_stock(stock);
	return (0);
}
