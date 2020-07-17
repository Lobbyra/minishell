/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:21:11 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/17 16:34:30 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_double_pipe(char *user_input, t_stock *s)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (user_input[i])
	{
		if (user_input[i] == '|' && status == 0)
		{
			s->error_strings = ft_strjoindel(s->error_strings, ERR_PIPE2, 1);
			return (1);
		}
		else if (user_input[i] == '|' && status == 1)
			status = 0;
		else if (user_input[i] != ' ')
			status = 1;
		i++;
	}
	return (0);
}
