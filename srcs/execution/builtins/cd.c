/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 13:53:35 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/29 18:22:18 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This is the source code of cd builtins. Here cd will not options or more
**	than one path.
*/

#include "minishell.h"

int		cd(char *path)
{
	errno = 0;
	chdir(path);
	if (errno != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	return (0);
}

/*
int		main(int argc, char **argv)
{
	l_printf("### DEBUG : curr_path = [%d", pwd(1));
	fflush(stdout);
	l_printf("]\n\n");
	fflush(stdout);
	if (argc == 2)
		cd(argv[1]);
	l_printf("### DEBUG : now_path = [%d", pwd(1));
	fflush(stdout);
	l_printf("]\n\n");
	fflush(stdout);
	return (0);
}
*/