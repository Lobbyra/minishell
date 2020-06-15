/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarrstr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:12:30 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/15 13:56:34 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putarrstr_fd(char **argv, char *sep, int fd)
{
	if (argv && fd > 0)
	{
		while (*(argv + 1))
		{
			write(fd, *argv, ft_strlen(*argv));
			write(fd, sep, ft_strlen(sep));
			argv++;
		}
		if (*argv)
		{
			write(fd, *argv, ft_strlen(*argv));
		}
	}
}
