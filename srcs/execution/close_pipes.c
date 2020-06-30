/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:32:21 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/30 17:32:30 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipes(int *pipes, int n_pipes)
{
	while (n_pipes > 0)
	{
		close(pipes[n_pipes - 1]);
		n_pipes--;
	}
}