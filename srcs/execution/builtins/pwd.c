/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 18:40:04 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/04 11:23:28 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This is the builtin source code of pwd.
**	Return errno if write or getcwd call exit with error.
*/

#include "minishell.h"

int		pwd(int fd)
{
	char *path;

	errno = 0;
	if (!(path = getcwd(NULL, MAX_PATH_LEN)))
		return (errno);
	if (write(fd, path, ft_strlen(path)) == -1 || write(fd, "\n", 1) == -1)
		return (errno);
	return (0);
}
