/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:50:24 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/13 16:53:25 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function return the index after a word. A word is a string of chars
**	defined by separators (' ', '|', '>', '<', '>>') non-escaped.
*/

#include "minishell.h"

int		pass_word(char *ui, int i)
{
	while (ui[i])
	{
		if (is_sep_char(ui, i) == TRUE)
			break ;
		if (ui[i] == '\'' && is_escaped(ui, i) == FALSE)
			i = pass_quote(ui, i);
		else if (ui[i] == '\"' && is_escaped(ui, i) == FALSE)
			i = pass_dquote(ui, i);
		else if ((ui[i] != '\"' && ui[i] != '\'') ||
			((ui[i] == '\"' || ui[i] == '\'') && is_escaped(ui, i) == TRUE))
			i++;
	}
	return (i);
}
