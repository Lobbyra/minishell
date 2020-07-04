/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdcaster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:13:35 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/04 13:42:07 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function take two file descriptors. One source and one destination.
** It will read all content from source (fd_src) fd and write it in
** destination (fd_dst).
** If a open or read error happend, this fun return -1.
** This function require get_next_line() of github/lobbyra/get_next_line .
*/

#include "minishell.h"

int			ft_fdcaster(int fd_src, int fd_dst)
{
	char	*buf;
	int		error;

	while ((error = get_next_line(fd_src, &buf)) > 0)
	{
		write(fd_dst, buf, ft_strlen(buf));
		write(fd_dst, "\n", 1);
		free(buf);
	}
	if (error == 0 && buf)
		write(fd_dst, buf, ft_strlen(buf));
	if (error == -1)
		return (error);
	return (0);
}
