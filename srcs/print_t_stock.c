/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_t_stock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 09:50:34 by Lobbyra           #+#    #+#             */
/*   Updated: 2020/04/21 10:13:46 by Lobbyra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_t_bool(t_stock *s)
{
	ft_putstr("ill_exit = ");
	if (s->ill_exit == TRUE)
		ft_putstr("TRUE\n");
	else
		ft_putstr("FALSE\n");
	ft_putstr("prev_cmd_is_piped = ");
	if (s->prev_cmd_is_piped == TRUE)
		ft_putstr("TRUE\n");
	else
		ft_putstr("FALSE\n");
}

void		print_t_stock(t_stock *s)
{
	ft_putstr("STOCK PRINT DEBUG\n");
	ft_putstr("user_input = ");
	if (s->user_input)
		ft_putstr(s->user_input);
	else
		ft_putstr("(null)");
	ft_putstr("\n");
	ft_putstr("command = ");
	if (s->command)
		ft_putstr(s->command);
	else
		ft_putstr("(null)");
	ft_putstr("\n");
	ft_putstr("$? = ");
	ft_putnbr(s->storage_return);
	ft_putstr("\n");
	ft_putstr("fds_pipe[0] = ");
	ft_putnbr(s->fds_pipe[0]);
	ft_putstr(" fds_pipe[1] = ");
	ft_putnbr(s->fds_pipe[1]);
	ft_putstr("\n");
	print_t_bool(s);
	ft_putstr("\n\n");
}
