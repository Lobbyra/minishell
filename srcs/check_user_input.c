/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_user_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:21:24 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/24 18:01:52 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	### CHECK_USER_INPUT ###
**	This function will check many error critic case with the ';' char.
**	For simplification we will use "ui" rather than "user_input" var.
**
**	For example :
**	- echo test ; ; echo exit
**	-            ; echo exit
**	- echo test ; | echo exit
**	contain an empty command.
**
**	Return 0 if user_input is ok or ERR_CRITIC if not.
**
**	It will modify exit_status if there is an error.
*/

static int	cui_print_error(int *exit_status)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("syntax error near unexpected token `;'\n", STDERR);
	*exit_status = 2;
	return (ERR_CRITIC);
}

/*
**	### CHECK_NOTHING_FIRST ###
**	This function check if there is no command between the start and the first ;
*/

static int	check_nothing_first(char *ui)
{
	int i;

	i = 0;
	i = pass_spaces(ui, i);
	if (ui[i] == ';')
		return (ERR_CRITIC);
	return (0);
}

static int	pass_anything_less_semicolon(char *ui, int i)
{
	while (ui[i])
	{
		if (ui[i] == '\"' && is_escaped(ui, i) == FALSE)
			i = pass_dquote(ui, i);
		else if (ui[i] == '\'' && is_escaped(ui, i) == FALSE)
			i = pass_quote(ui, i);
		else if (ui[i] == ';' && is_escaped(ui, i) == FALSE)
		{
			break ;
		}
		else
			i++;
	}
	return (i);
}

static int	check_nothing_between(char *ui)
{
	int i;

	i = 0;
	while (ui[i])
	{
		if (ui[i] == ';')
		{
			i++;
			while (ui[i] == ' ')
				i++;
			if (ui[i] == ';')
				return (ERR_CRITIC);
		}
		i = pass_anything_less_semicolon(ui, i);
	}
	return (0);
}

int			check_user_input(char *ui, int *exit_status)
{
	if (check_nothing_first(ui) == ERR_CRITIC)
		return (cui_print_error(exit_status));
	if (check_nothing_between(ui) == ERR_CRITIC)
		return (cui_print_error(exit_status));
	if (check_semicolon_pipe(ui) == ERR_CRITIC)
		return (cui_print_error(exit_status));
	return (0);
}
