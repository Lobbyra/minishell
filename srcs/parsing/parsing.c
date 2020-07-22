/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:02:38 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/21 16:28:34 by jereligi         ###   ########.fr       */
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
	char	**tmp;

	l_printf("cmd user: |%s|\n\n", stock->user_input);
	check_end_backslash(stock);
	l_printf("\033[32mcheck end_backslash [ok]\033[37m\n");
	if (check_double_pipe(stock->user_input, stock) != 0)
		return (ERR_SYNTAX);
	verif_redirection_env_var(stock);
	env_var(stock);
	tmp = split_cmd(stock->user_input);
	return (debug_parsing_utils(stock, tmp));
}

int			parsing(t_stock *stock)
{
	char	**tmp;

	stock->is_exec_abort = FALSE;
	if (stock->is_debug == TRUE)
		return (debug_parsing(stock));
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
