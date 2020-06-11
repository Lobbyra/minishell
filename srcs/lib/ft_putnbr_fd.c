/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 10:04:23 by Lobbyra           #+#    #+#             */
/*   Updated: 2020/04/21 10:05:01 by Lobbyra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648 && fd > 0)
		write(fd, "-2147483648", 11);
	else if (nb < 0 && fd > 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(nb * (-1), fd);
	}
	else if (nb >= 10 && fd > 0)
		ft_putnbr_fd(nb / 10, fd);
	if (nb >= 0 && fd > 0)
		ft_putchar_fd((nb % 10) + '0', fd);
}
