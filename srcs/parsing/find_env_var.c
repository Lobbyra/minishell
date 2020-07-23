/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:18:12 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/23 13:49:53 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			find_env_var(char **tab_env_var, char **envp, char **value,
int i)
{
	int n;
	int	len_var;

	n = 0;
	while (envp[n])
	{
		len_var = ft_strlen_c(envp[n], '=');
		if (ft_strncmp(tab_env_var[i], envp[n], len_var) == 0)
		{
			len_var = ft_strlen(tab_env_var[i]);
			if (ft_strncmp(tab_env_var[i], envp[n], len_var) == 0)
			{
				free(value[i]);
				value[i] = get_value(envp[n]);
				break ;
			}
		}
		n++;
	}
}
