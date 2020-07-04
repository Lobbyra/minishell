/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:46 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/07/04 11:16:06 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		write_right(t_stock *s, char *file)
{
	if (s->is_debug == TRUE)
		l_printf("write: %s\n", file);
	if (open(file, O_WRONLY) == -1)
	{
		s->error_strings = ft_strjoindel(s->error_strings, \
		ft_strjoin("minishell: ", file), 2);
		s->error_strings = ft_strjoindel(s->error_strings, ERR_PERM_DENIED, 1);
		if (s->is_debug == TRUE)
			l_printf("\033[31mno writing rights \033[37m[%s]\n", file);
		return (0);
	}
	return (1);
}

static int		read_right(t_stock *s, char *file)
{
	if (s->is_debug == TRUE)
		l_printf("read: %s\n", file);
	if (open(file, O_RDONLY) == -1)
	{
		s->error_strings = ft_strjoindel(s->error_strings, \
		ft_strjoin("minishell: ", file), 3);
		s->error_strings = ft_strjoindel(s->error_strings, ERR_PERM_DENIED, 1);
		if (s->is_debug == TRUE)
			l_printf("\033[31mno reading rights \033[37m[%s]\n", file);
		return (0);
	}
	return (1);
}

static int		check_file(t_stock *s, int i, int n)
{
	if (s->is_debug == TRUE)
		l_printf("check file\n");
	if (n > 0)
	{
		if (s->jobs[i][n - 1][0] == '>')
		{
			if (!write_right(s, s->jobs[i][n]))
				return (0);
		}
		else if (s->jobs[i][n - 1][0] == '<')
		{
			if (!read_right(s, s->jobs[i][n]))
				return (0);
		}
	}
	else
	{
		if (s->jobs[i - 1][n][0] == '>')
		{
			if (!write_right(s, s->jobs[i][n]))
				return (0);
		}
		else if (s->jobs[i - 1][n][0] == '<')
		{
			if (!read_right(s, s->jobs[i][n]))
				return (0);
		}
	}
	return (0);
}

int				verif_files(t_stock *s)
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
			{
				check_file(s, i, n);
				status = 0;
			}
			n++;
		}
		i++;
	}
	return (0);
}
