/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 11:03:17 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/10 14:52:37 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		print_err_main(int error)
{
	if (error == ERR_MALLOC)
		ft_putstr(MSG_ERR_MALLOC);
	return (1);
}

static void		reset_stock(t_stock *stock)
{
	if (stock->user_input)
	{
		free(stock->user_input);
		stock->user_input = NULL;
	}
	if (stock->command)
	{
		printf("address de cmd = %p\n", stock->command);
		fflush(stdout);
		// free(stock->command);
		stock->command = NULL;
	}
}

static int		ft_wait_instruction(char **str)
{
	int		error;

	if (!str)
		return (ERROR);
	if (*str != NULL)
		free(*str);
	error = get_next_line(0, str);
	if (error == -1)
	{
		free(*str);
		return (ERROR);
	}
	return (0);
}

static int	init_stock(char **envp, t_stock **stock)
{
	t_stock *new;

	if (!(new = (t_stock*)malloc(sizeof(t_stock))))
		return (ERR_MALLOC);
	new->envp = NULL;
	new->user_input = NULL;
	new->storage_return = 0;
	new->ill_exit = FALSE;
	new->is_debug_mode = FALSE;
	new->prev_cmd_is_piped = FALSE;
	if ((new->envp = ft_strarrdup(envp)) == NULL)
	{
		free(new);
		return (ERR_MALLOC);
	}
	new->fds_pipe[0] = 0;
	new->fds_pipe[1] = 0;
	*stock = new;
	return (0);
}

int				main(int argc, char **argv, char **envp)
{
	int error;
	t_stock *stock;

	if ((error = init_stock(envp, &stock)) != 0)
		return (print_err_main(error));
	if (argc == 2 && ft_strcmp(argv[1], "--debug") == 0)
		stock->is_debug_mode = TRUE;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	while (stock->ill_exit == FALSE)
	{
		errno = 0;
		error = 0;
		if ((error = ft_wait_instruction(&(stock->user_input))) != 0)
			print_err_main(error);
		if ((stock->user_input = ft_strcleaner(stock->user_input)) == NULL)
			print_err_main(ERR_MALLOC);
		else if ((error = minishell(stock)) != 0)
			print_err_main(error);
		reset_stock(stock);
	}
	ft_freestrs(stock->envp);
	free(stock);
	return (0);
}
