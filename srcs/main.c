/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:47:17 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/15 15:29:54 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	t_stock	*stock;

	if (!(stock = init_stock(envp)))
		return (1);
	free_t_stock(stock);
	return (0);
}