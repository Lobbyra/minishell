/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_instruction_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:05:40 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/20 17:18:32 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	### IS_NOTHIN_N_PIPED ###
**	Static function of CHECK_ENTIRE_UI
**	It check if there is nothing between non-quoted ; and |.
*/
t_bool		is_nothing_n_piped(char *ui, int i)
{
	i++;
	i = pass_spaces(ui, i);
	if (ui[i] == '|')
		return (TRUE);
	return (FALSE);
}

/*
**	### CHECK_ENTIRE_UI ###
**	Function that check case of echo bonjour ; | echo salut.
**	ui mean user_input
*/
int			check_entire_ui(char *ui)
{
	int i;

	i = 0;
	while (ui[i])
	{
		i = pass_spaces(ui, i);
		if (ui[i] == ';')
		{
			if (is_nothing_n_piped(ui, i) == TRUE)
			{
				ft_putstr_fd(ERR_CRIT_MSG, STDERR);
				return (ERR_CRITIC);
			}
			else
				i++;
		}
		else if (is_sep_char(ui, i) == TRUE)
			i++;
		else
			i = pass_word(ui, i);
	}
	return (0);
}

/*
**	Static function of check_user_input.
*/

static int	print_error(void)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("syntax error near unexpected token `;'\n", STDERR);
	return (ERR_CMD_VOID);
}

/*
**	static function of check_user_input.
*/

static void	skip_cmd(char **str)
{
	char **save_str;

	save_str = str;
	while (**str)
	{
		if (((**str == '\"' || **str == '\'') && *str == *save_str) ||
			((**str == '\"' || **str == '\'') && *(*str - 1) != '\\'))
			skip_part(str);
		else if ((**str == ';' && *str == *save_str) ||
			(**str == ';' && *(*str - 1) != '\\'))
			break ;
		else
			(*str)++;
	}
}

/*
**	This function will check if user_input not contain an empty command.
**	For example : echo test ; ; echo exit
**	contain an empty command.
*/

int			check_user_input(char *user_input)
{
	char	*i_ui;

	i_ui = user_input;
	while (*i_ui)
	{
		ft_skip(&i_ui, ' ');
		if ((*i_ui == ';' && i_ui == user_input) ||
			(*i_ui == ';' && *(i_ui - 1) != '\\'))
			return (print_error());
		else
			skip_cmd(&i_ui);
		i_ui++;
	}
	if (check_entire_ui(user_input) == ERR_CRITIC)
		return (ERR_CRITIC);
	return (0);
}

