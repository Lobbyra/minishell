/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_instruction_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:05:40 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/03 18:39:23 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Static function of check_user_input.
*/
static int	print_error(void)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("syntax error near unexpected token `;'\n", 2);
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
	return (0);
}

int		panic_wait_instruction(char **to_free, int err)
{
	if (*to_free != NULL)
	{
		free(*to_free);
		*to_free = NULL;
	}
	return (err);
}