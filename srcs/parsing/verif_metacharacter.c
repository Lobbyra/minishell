/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_metacharacter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:15:46 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/07/09 18:31:47 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				is_metacharacter(char c)
{
	if (c == '>' || c == '<')
		return (1);
	return (0);
}

int				verif_metacharacter(t_stock *s, char **cmd)
{
	int i;

	i = 0;
	while (cmd[i] && cmd[i + 1])
	{
		if (is_metacharacter(cmd[i][0]) && is_metacharacter(cmd[i + 1][0]))
		{
			s->error_strings = ft_strjoindel(s->error_strings, \
			"minishell: syntax error near unexpected token `", 1);
			s->error_strings = ft_strjoindel(s->error_strings, \
			ft_strjoin(cmd[i + 1], "'\n"), 3);
			l_printf("%s", s->error_strings);
			return (0);
		}
		i++;
	}
	return (1);
}
