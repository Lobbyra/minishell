/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:49:03 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/22 16:17:30 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	This function will alloc new with n blocks accord to the final amount of
**	args.
**	Each blocks of this array will be alloc at 1 byte == '\0' to do a sort of
**	strjoin on each strings.
*/

static char	**panic_init_split(char **new, char **i_new)
{
	while (i_new > new)
	{
		free(*i_new);
		i_new--;
	}
	if (new)
		free(new);
	return (NULL);
}

static int	pre_alloc(char **new, int n_args)
{
	int n;

	n = 0;
	while (n < n_args)
	{
		if (!(*new = (char*)malloc(sizeof(char) * 1)))
			break ;
		**new = '\0';
		n++;
		new++;
	}
	return (n);
}

char		**init_split(int n_args)
{
	char	**new;
	int		ptrs_alloced;
	
	if (!(new = (char**)malloc(sizeof(char*) * (n_args))))
		return (NULL);
	ptrs_alloced = pre_alloc(new, n_args);
	if (ptrs_alloced != n_args)
		return (panic_init_split(new, new + ptrs_alloced));
	return (new);
}