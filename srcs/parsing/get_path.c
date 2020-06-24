/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:10:00 by jereligi          #+#    #+#             */
/*   Updated: 2020/06/24 16:10:39 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path(char **envp)
{
	int		i;
	char	*tmp;
	char	**path;

	if (!(tmp = (char *)malloc(sizeof(char) * 5)))
		return (0);
	tmp[0] = '\0';
	i = 0;
	while (envp[i])
	{
		ft_strlcpy(tmp, envp[i], 4);
		if ((strcmp(tmp, "PATH")) == 0)
			break ;
		i++;
	}
	free(tmp);
	path = ft_split(&envp[i][5], ":");
	return (path);
}
