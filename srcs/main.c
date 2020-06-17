/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:47:17 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/17 16:37:58 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



/*
** Read stdin to get command from the user.
** Return 1 if ctrl-D.
** Return ERR_ERRNO if gnl error.
** Return 0 else.
*/
static int	wait_instruction(char **cmd)
{
	int status;

	status = get_next_line(0, cmd);
	if (status == -1)
		return (ERR_ERRNO);
	if (status == 2)
		return (1);
	return (0);
}

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
		if ((error = wait_instruction(&command)) == ERR_ERRNO)
			error_printer(error);
		if (error == SIG_CTRLD)
			break ;
		if (error == 0 && (error = command_to_jobs(stock, command)))
			error_printer(error);
		// print_jobs(stock->jobs, stock->n_jobs);
		if (error == 0 && (error = parsing(stock) != 0))
			error_printer(error);
		if (error != ERR_MALLOC && (error = execution(stock)) != 0)
			error_printer(error);
		reset(stock, command);
	}
	free_t_stock(stock);
	return (0);
}
