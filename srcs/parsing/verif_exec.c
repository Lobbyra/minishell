/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:08:03 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/23 16:50:51 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function adds the right path to the executable if it exists
*/

#include "minishell.h"

char		*ft_pwd(void)
{
	char *str;

	if (!(str = (char*)malloc(sizeof(char) * 4028 + 1)))
		return (NULL);
	getcwd(str, 4028);
	return (str);
}

static int	check_is_slash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '/' || str[i] == '\'' || str[i] == '\"'))
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
		if (status == 2)
		{
			s->jobs[i][0] = ft_strjoindel(ft_pwd(), \
			ft_strjoindel("/", s->jobs[i][0], 2), 3);
		}
		else if (status == 0)
			management_check_all_path(s, i);
		i++;
	}
	return (0);
}
