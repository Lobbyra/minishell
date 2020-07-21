/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:02:38 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/21 13:51:12 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	debug_parsing_utils(t_stock *stock, char **tmp)
{
	if (verif_metacharacter(stock, tmp) == 0)
		return (ERR_SYNTAX);
	if (command_to_jobs(stock, tmp) == 0)
		l_printf("\033[32mcommand_to_jobs [ok]\033[37m\n\n");
	ft_putarrarrstrs(stock->jobs, stock->n_jobs);
	verif_exec(stock);
	check_redirection_null(stock);
	return (0);
}

static int	debug_parsing(t_stock *stock)
{
	int		i;
	int		err;
	char	**tmp;

	i = 0;
	l_printf("cmd user: |%s|\n\n", stock->user_input);
	if (check_quote(stock) == 3)
		return (ERR_SYNTAX);
	l_printf("\033[32mcheck quote [ok]\033[37m\n");
	if ((err = check_pipe(stock)) != 0)
		return (err);
	l_printf("\033[32mcheck pipe [ok]\033[37m\n");
	check_end_backslash(stock);
	l_printf("\033[32mcheck end_backslash [ok]\033[37m\n");
	if (check_double_pipe(stock->user_input, stock) != 0)
		return (ERR_SYNTAX);
	verif_redirection_env_var(stock);
	env_var(stock);
	tmp = split_cmd(stock->user_input);
	debug_parsing_utils(stock, tmp);
	return (0);
}

int			parsing(t_stock *stock)
{
	int		i;
	int		err;
	char	**tmp;

	i = 0;
	stock->is_exec_abort = FALSE;
	if (stock->is_debug == TRUE)
		return (debug_parsing(stock));
	if (check_quote(stock) == 3)
		return (ERR_SYNTAX);
	if ((err = check_pipe(stock)) != 0)
		return (err);
	check_end_backslash(stock);
	if (check_double_pipe(stock->user_input, stock) != 0)
		return (ERR_SYNTAX);
	verif_redirection_env_var(stock);
	env_var(stock);
	tmp = split_cmd(stock->user_input);
	if (verif_metacharacter(stock, tmp) == 0)
		return (ERR_SYNTAX);
	command_to_jobs(stock, tmp);
	verif_exec(stock);
	check_redirection_null(stock);
	return (0);
}
