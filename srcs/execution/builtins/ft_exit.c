/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 13:43:09 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/22 17:54:43 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Builtin source code of exit, in minishell, this feature does not support
**	options or argument. So in all cases we will need to insert in parameter
**	our stock->exit_status.
*/

#include "minishell.h"

static t_bool	is_str_num(char *arg)
{
	while (*arg && (*arg >= '0' && *arg <= '9'))
		arg++;
	if (*arg == '\0')
		return (TRUE);
	return (FALSE);
}

static void		print_err(char *arg, int status)
{
	ft_putstr_fd("minishell: exit: ", STDERR);
	if (status == 255)
	{
		ft_putstr_fd(arg, STDERR);
		ft_putstr_fd(": numeric argument required\n", STDERR);
		exit(255);
	}
	else
	{
		ft_putstr_fd("too many arguments\n", STDERR);
		exit(1);
	}
}

void	ft_exit(char **job)
{
	int job_len;
	
	job_len = ft_strarrlen(job);
	if (job_len == 1)
		exit(0);
	else
	{
		if (*(job + 1) && is_str_num(*(job + 1)) == FALSE)
			print_err(*(job + 1), 255);
		else if (job_len > 2)
			print_err("", 1);
		exit(ft_atoi(*(job + 1)));
	}
}
