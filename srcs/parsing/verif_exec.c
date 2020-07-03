/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:08:03 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/03 12:02:30 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_pwd(void)
{
	char *str;

	if (!(str = (char*)malloc(sizeof(char) * 4028 + 1)))
		return (NULL);
	getcwd(str, 4028);
	return (str);
}

static int	check_path(t_stock *s, int i)
{
	int			debug;
	struct stat	buf;
	
	errno = 0;
	stat(s->jobs[i][0], &buf);
	debug = errno;
	if (debug != 0)
		l_printf("%s\n", strerror(debug));
	if (debug != 0)
	{
		ft_strjoindel(s->error_strings, \
		ft_strjoin("minishell: no such file or directory: ", s->jobs[i][0]), 2);
		l_printf("error path: [%s]\n", s->jobs[i][0]);
		s->jobs[i][0] = NULL;
		return (1);
	}
	return (0);
}

static int	check_is_slash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '/')
			return (1);
		else if (str[i] == '/')
			return (2);
		i++;
	}
	return (0);
}

int			verif_exec(t_stock *s)
{
	int i;
	int	status;

	i = 0;
	status = 0;
	while (s->jobs[i])
	{
		status = check_is_slash(s->jobs[i][0]);
		if (status == 1)
			check_path(s, i);
		else if (status == 2)
		{
			s->jobs[i][0] = ft_strjoindel(ft_pwd(), \
			ft_strjoindel("/", s->jobs[i][0], 2), 3);
			check_path(s, i);
		}
		else if (status == 0)
			management_check_all_path(s, i, s->is_debug);
		i++;
	}
	return (0);
}
