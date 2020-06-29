/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:02:38 by jereligi          #+#    #+#             */
/*   Updated: 2020/06/29 14:34:02 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		parsing(t_stock *stock)
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
	if (command_to_jobs(stock, tmp) == 0)
		printf("\n\033[32mcommand_to_jobs [ok]\033[37m\n");
	verif_exec(stock);
	return (0);
}