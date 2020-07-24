/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection_null.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:03:53 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/24 18:03:05 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		redirection_null(t_stock *s, int n, int i, int *status)
{
	if (s->is_cmd_closed == TRUE)
		s->error_strings = ft_strjoindel(s->error_strings, ERR_PIPE3, 1);
	else
		s->error_strings = ft_strjoindel(s->error_strings, ERR_REDIREC, 1);
	*status = 0;
	if (n > 0)
	{
		ft_strarrfree(s->jobs[i]);
		s->jobs[i] = NULL;
	}
	else
	{
		ft_strarrfree(s->jobs[i]);
		s->jobs[i - 1] = NULL;
	}
	s->exit_status = 2;
}

int				check_redirection_null(t_stock *s)
{
	int i;
	int	n;
	int status;

	i = 0;
	status = 0;
	while (s->jobs[i])
	{
		n = 0;
		while (s->jobs[i][n])
		{
			if (is_metacharacter(s->jobs[i][n][0]))
				status = 1;
			else if (status == 1)
				status = 0;
			n++;
		}
		if (status == 1)
			redirection_null(s, n, i, &status);
		i++;
	}
	return (0);
}
