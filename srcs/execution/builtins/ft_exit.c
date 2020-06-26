/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 13:43:09 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/26 17:56:44 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Builtin source code of exit, in minishell, this feature does not support
**	options or argument. So in all cases we will need to insert in parameter
**	our stock->exit_status.
*/

#include "minishell.h"

void	ft_exit(int err)
{
	exit(err);
}

/*
int		main(int argc, char **argv)
{
	ft_exit(1554);
	return (0);
}
*/