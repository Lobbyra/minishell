/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 13:20:02 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/04 11:22:38 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env(char **envp, int fd)
{
	errno = 0;
	if (ft_protected_putarrstr_fd(envp, "\n", fd) != 0)
		return (errno);
	if (write(fd, "\n", 1) == -1)
		return (errno);
	return (0);
}
