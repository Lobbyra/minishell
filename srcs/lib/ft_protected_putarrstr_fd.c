/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protected_putarrstr_fd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 13:29:20 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/24 13:33:08 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_protected_putarrstr_fd(char **argv, char *sep, int fd)
{
	if (argv && fd > 0)
	{
		while (*(argv + 1))
		{
			if (write(fd, *argv, ft_strlen(*argv)) == -1 ||
				write(fd, sep, ft_strlen(sep)) == -1)
				return (errno);
			argv++;
		}
		if (*argv)
		{
			if (write(fd, *argv, ft_strlen(*argv)) == -1)
				return (errno);
		}
	}
	return (0);
}
