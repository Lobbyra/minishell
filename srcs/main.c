/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:47:17 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/21 18:10:51 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Used to free variables alloced for just one command.
*/

static t_bool	debug_arg_detection(int argc, char **argv)
{
	if (argc >= 2 && ft_strcmp(argv[1], "--debug") == 0)
		return (TRUE);
	return (FALSE);
}

t_bool g_is_ctrlc = FALSE;

static void		handler(int nothing)
{
	nothing = 0;
	l_printf("\r");
	print_prompt();
	g_is_ctrlc = TRUE;
}

static void		quithandler(int nothing)
{
	nothing = 0;
	g_is_ctrlc = TRUE;
}

int				main(int argc, char **argv, char **envp)
{
	int		err;
	t_stock	*stock;

	signal(SIGINT, handler);
	signal(SIGQUIT, quithandler);
	if (!(stock = init_stock(envp)))
		return (1);
	stock->is_debug = debug_arg_detection(argc, argv);
	while (1)
	{
		err = 0;
		if ((err = wait_instruction(stock)) != 0 && err != SIG_CTRLD)
			error_manager(stock, err);
		if (err == SIG_CTRLD)
			break ;
		if (err == 0 && (err = parsing(stock)) != 0)
			error_manager(stock, err);
		ft_putstr_fd(stock->error_strings, STDERR);
		if ((err == 0 || err == ERR_EXIT) && (err = execution(stock)) != 0)
			error_manager(stock, err);
		reset(stock);
	}
	free_t_stock(stock);
	l_printf("exit\n");
	return (0);
}
