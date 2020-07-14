/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:56:18 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/14 18:19:17 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function will look through all arg in jobs and clean it.
**	In clean we mean removing backslash escaper, and, finally removing quotes.
*/

#include "minishell.h"

char	***jobs_cleaner(char ***jobs)
{
	char **i_arg;
	char ***save_jobs;

	save_jobs = jobs;
	while (*jobs)
	{
		i_arg = *jobs;
		while (*i_arg)
		{
			*i_arg = arg_cleaner(*i_arg);
			i_arg++;
		}
		jobs++;
	}
	return (save_jobs);
}
