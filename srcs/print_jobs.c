/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 16:54:44 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/04 11:19:33 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_jobs(char ***jobs, int n_jobs)
{
	int i;

	i = 0;
	while (i < n_jobs)
	{
		l_printf("[%d] = {", i);
		if (!jobs[i])
			l_printf("NULL");
		else
			ft_putarrstr(jobs[i], ", ");
		write(1, "}\n", 2);
		i++;
	}
}
