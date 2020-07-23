/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:56:18 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/23 18:43:58 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	### JOBS_CLEANER ###
**	This function will clean all strings in a job. It will delete surround
**	quotes and escape char non-quoted and specific escape in double-quote.
*/

#include "minishell.h"

char	**job_cleaner(char **job)
{
	int i;

	i = 0;
	while (job[i])
	{
		job[i] = arg_cleaner(job[i]);
		i++;
	}
	return (job);
}
