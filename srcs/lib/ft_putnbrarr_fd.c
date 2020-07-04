/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrarr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 13:43:45 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/04 13:43:48 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putnbrarr_fd(int *tab, int size, int fd)
{
	int i;

	i = 0;
	if (tab && fd > 0)
	{
		while (i + 1 < size)
		{
			ft_putnbr_fd(tab[i++], fd);
			write(fd, ", ", 2);
		}
		if (i < size)
			ft_putnbr_fd(tab[i], fd);
	}
}
