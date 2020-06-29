/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:41:42 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/29 17:01:00 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	panic_init_pipes(int *new)
{
	free(new);
	return (ERR_MALLOC);
}

int			init_pipes(int **pipes, int n_jobs)
{
	int *new;
	int n_pipes;

	errno = 0;
	n_pipes = n_jobs * 2 - 4;
	if (n_jobs == 1)
	{
		*pipes = NULL;
		return (0);
	}
	if (!(new = (int*)malloc(sizeof(int) * (n_pipes))))
		return (ERR_MALLOC);
	while (n_jobs > 1)
	{
		if (pipe(new + (n_jobs * 2 - 4)) == -1)
			return (panic_init_pipes(new));
		n_jobs--;
	}
	if (pipe(new) == -1)
		return (panic_init_pipes(new));
	*pipes = new;
	return (0);
}

// int		main(int argc, char **argv)
// {
// 	if (argc >= 2)
// 	{
// 		int *new;

// 		new = init_pipes(atoi(argv[1]));
// 		if (new)
// 			ft_putnbrarr_fd(new, atoi(argv[1]) * 2 - 2, 1);
// 		else
// 			printf("(NULL)\n");
// 	}
// 	return (0);
// }