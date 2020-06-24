/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:02:38 by jereligi          #+#    #+#             */
/*   Updated: 2020/06/24 18:35:37 by jereligi         ###   ########.fr       */
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
	
	i = 0;
	while (tmp[i])
		l_printf("[%s]\n", tmp[i++]);
	// verif_exec(stock, tmp);
	command_to_jobs(stock, tmp);
	return (0);
}