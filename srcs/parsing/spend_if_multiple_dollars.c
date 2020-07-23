/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spend_if_multiple_dollars.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:49:15 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/23 19:02:01 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	spend_if_multiple_dollars(char *user_input, int *i)
{
	if (user_input[*i] == '$' && user_input[*i + 1] == '$')
	{
		while (user_input[*i] && user_input[*i] == '$' &&
		user_input[*i + 1] == '$')
			(*i)++;
		(*i)--;
	}
}
