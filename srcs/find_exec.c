/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 13:31:28 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/02 13:46:16 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function take a char ** that contain a job. It will return the ptr of
**	the string where the path of the string is saved.
*/

#include "minishell.h"

char	**find_exec(char **job)
{
	while (*job)
	{
		if (ft_strcmp(*job, ">") == 0 ||
			ft_strcmp(*job, "<") == 0 ||
			ft_strcmp(*job, ">>") == 0)
			job += 2;
		else
			return (job);
	}
	return (NULL);
}
