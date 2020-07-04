/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 16:15:44 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/04 11:18:05 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Look ./headers/minishell.h to see err code values.
** Look ./headers/error_messages.h to see err messages.
*/

void	error_printer(int err)
{
	if (err == ERR_MALLOC)
		ft_putstr_fd(ERR_MALLOC_MSG, STDERR);
}
