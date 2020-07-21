/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 13:20:02 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/21 18:50:50 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env(char **job, char **envp, int fd)
{
	char *err;

	err = "minishell: env: Arguments or options are not permitted.\n";
	errno = 0;
	if (ft_strarrlen(job) > 1)
	{
		ft_putstr_fd(err, STDERR);
		return (1);
	}
	if (ft_protected_putarrstr_fd(envp, "\n", fd) != 0)
		return (errno);
	if (write(fd, "\n", fd) == -1)
		return (errno);
	return (0);
}
