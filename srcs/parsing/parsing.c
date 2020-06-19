/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:02:38 by jereligi          #+#    #+#             */
/*   Updated: 2020/06/19 13:53:16 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int		parsing(t_stock *stock)
{
	int		i;

	i = 0;
	l_printf("|%s|\n", stock->user_input);
	if (check_quote(stock->user_input) == 0)
		l_printf("end of check quote\n");
	return (0);
}
