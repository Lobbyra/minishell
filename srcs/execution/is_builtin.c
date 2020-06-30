/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:50:50 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/30 17:51:10 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_builtin(char *path)
{
	t_bool	ret;
	char	*exec_name;
	
	ret = FALSE;
	if (!(exec_name = ft_basename(path)))
		return (FALSE);
	if (ft_strcmp(exec_name, "cd") == 0)
		ret = TRUE;
	else if (ft_strcmp(exec_name, "echo") == 0)
		ret = TRUE;
	else if (ft_strcmp(exec_name, "env") == 0)
		ret = TRUE;
	else if (ft_strcmp(exec_name, "export") == 0)
		ret = TRUE;
	else if (ft_strcmp(exec_name, "exit") == 0)
		ret = TRUE;
	else if (ft_strcmp(exec_name, "pwd") == 0)
		ret = TRUE;
	else if (ft_strcmp(exec_name, "unset") == 0)
		ret = TRUE;
	free(exec_name);
	return (ret);
}