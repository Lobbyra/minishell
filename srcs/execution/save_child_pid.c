/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_child_pid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 11:24:47 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/27 11:58:00 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	### SAVE_CHILD_PID ###
**	This function will add, at the end of an arr, the pid of the child created.
**	If there isn't child saved actually, it will create the arr.
**	Return ERR_MALLOC if memory allocation fail, 0 else.
**	The arr end by 0.
*/

int		pids_counter(pid_t *arr)
{
	int i;

	i = 0;
	if (arr == NULL)
		return (0);
	else
	{
		while (arr[i] != 0)
			i++;
	}
	return (i);
}

pid_t	*add_child(t_stock *s, pid_t child)
{
	int		i;
	pid_t	*new;
	int		n_childs;

	i = 0;
	n_childs = pids_counter(s->child_pids);
	if (!(new = (pid_t*)malloc(sizeof(pid_t) * (n_childs + 2))))
		return (NULL);
	while (i < n_childs)
	{
		new[i] = s->child_pids[i];
		i++;
	}
	new[i] = child;
	i++;
	new[i] = 0;
	free(s->child_pids);
	return (new);
}

int		save_child_pid(t_stock *s, pid_t child)
{
	if (s->child_pids == NULL)
	{
		if (!(s->child_pids = (pid_t*)malloc(sizeof(pid_t) * (2))))
			return (ERR_MALLOC);
		s->child_pids[0] = child;
		s->child_pids[1] = 0;
	}
	else
	{
		if ((s->child_pids = add_child(s, child)) == NULL)
			return (ERR_MALLOC);
	}
	return (0);
}
