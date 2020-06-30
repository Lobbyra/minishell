/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:47:17 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/30 13:47:21 by jecaudal         ###   ########.fr       */
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

	l_printf("%s", OUR_PS1);
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
static void	reset(t_stock *stock)
{
	int i_jobs;

	i_jobs = 0;
	// if (stock->jobs != NULL)
	// {
	// 	while (i_jobs < stock->n_jobs)
	// 		ft_freestrs(stock->jobs[i_jobs++]);
	// 	free(stock->jobs);
	// 	stock->jobs = NULL;
	// }
	stock->jobs = NULL;
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

static t_bool	debug_arg_detection(int argc, char **argv)
{
	if (argc >= 2 && ft_strcmp(argv[1], "--debug") == 0)
		return (TRUE);
	return (FALSE);
}

static void		ctrl_c_management(int nothing)
{
	l_printf("\r\n%s", OUR_PS1);
}

int			main(int argc, char **argv, char **envp)
{
	int		err;
	t_stock	*stock;

	signal(SIGINT, ctrl_c_management);
	if (!(stock = init_stock(envp)))
		return (1);
	stock->is_debug = debug_arg_detection(argc, argv);
	while (1)
	{
		err = 0;
		if ((err = wait_instruction(&(stock->user_input))) == ERR_ERRNO)
			error_printer(err);
		if (err == SIG_CTRLD)
			break ;
		if (err == 0 && (err = parsing(stock) != 0))
			error_printer(err);
		if ((err == 0 || err == ERR_EXIT) && (err = execution(stock)) != 0)
			error_printer(err);
		reset(stock);
	}
	free_t_stock(stock);
	l_printf("exit\n");
	return (0);
}
