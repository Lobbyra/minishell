/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:02:38 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/07 15:04:25 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	debug_parsing(t_stock *stock)
{
	int		i;
	char	**tmp;

	i = 0;
	l_printf("|%s|\n", stock->user_input);
	if (check_quote(stock) == 3)
		return (ERR_SYNTAX);
	printf("\033[32mcheck quote [ok]\033[37m\n");
	check_pipe(stock);
	printf("\033[32mcheck pipe [ok]\033[37m\n");
	check_end_backslash(stock);
	printf("\033[32mcheck end_backslash [ok]\033[37m\n");
	if (check_double_pipe(stock->user_input) != 0)
		return (ERR_SYNTAX);
	env_var(stock);
	tmp = split_command(stock->user_input);
	if (verif_metacharacter(stock, tmp) == 0)
		return (ERR_SYNTAX);
	if (command_to_jobs(stock, tmp) == 0)
		printf("\n\033[32mcommand_to_jobs [ok]\033[37m\n");
	ft_putarrarrstrs(stock->jobs, stock->n_jobs);
	verif_exec(stock);
	verif_files(stock);
	return (0);
}

int			parsing(t_stock *stock)
{
	int		i;
	char	**tmp;

	i = 0;
	if (stock->is_debug == TRUE)
		return (debug_parsing(stock));
	if (check_quote(stock) == 3)
		return (ERR_SYNTAX);
	check_pipe(stock);
	check_end_backslash(stock);
	if (check_double_pipe(stock->user_input) != 0)
		return (ERR_SYNTAX);
	env_var(stock);
	tmp = split_command(stock->user_input);
	if (verif_metacharacter(stock, tmp) == 0)
		return (ERR_SYNTAX);
	command_to_jobs(stock, tmp);
	verif_exec(stock);
	verif_files(stock);
	return (0);
}
