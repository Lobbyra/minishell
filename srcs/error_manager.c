/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 16:15:44 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/23 16:00:01 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Look ./headers/minishell.h to see err code values.
** Look ./headers/error_messages.h to see err messages.
*/

void	error_manager(t_stock *stock, int err)
{
	if (err == ERR_MALLOC)
		ft_putstr_fd(ERR_MALLOC_MSG, STDERR);
	else if (err == ERR_CRITIC)
	{
		if (stock->buf_user_input)
			free(stock->buf_user_input);
		if (stock->user_input)
			free(stock->user_input);
		stock->buf_user_input = NULL;
		stock->user_input = NULL;
		stock->exit_status = 2;
	}
	else
		stock->exit_status = 2;
}
