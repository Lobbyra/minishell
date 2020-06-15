/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:12:30 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/15 14:50:45 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putarrstr(char **argv, char *sep)
{
	if (argv)
	{
		while (*(argv + 1))
		{
			write(1, *argv, ft_strlen(*argv));
			write(1, sep, ft_strlen(sep));
			argv++;
		}
		if (*argv)
		{
			write(1, *argv, ft_strlen(*argv));
		}
	}
}
