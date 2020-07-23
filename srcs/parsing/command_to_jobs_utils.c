/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_to_jobs_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:15:18 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/23 16:35:00 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		nopipe(char **command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i][0] == '|')
			return (1);
		i++;
	}
	return (0);
}
