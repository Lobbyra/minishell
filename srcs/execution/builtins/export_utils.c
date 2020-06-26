/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:55:00 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/26 16:01:26 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This is additionnal functions for export minishell builtin.
*/

#include "minishell.h"

void		print_envp_export(char **envp, int fd)
{
	char	*temp;
	char	**dup;
	char	**save_dup;

	dup = ft_strarrdup(envp);
	save_dup = dup;
	ft_sort_strs(dup);
	while (*dup)
	{
		if (**dup != '_')
		{
			temp = *dup;
			write(fd, "declare -x ", 11);
			write(fd, temp, ft_strlen_c(temp, '=') + 1);
			ft_skip_until(&temp, '=');
			temp++;
			write(fd, temp, ft_strlen(temp));
			write(fd, "\n", 1);
		}
		dup++;
	}
	ft_freestrs(save_dup);
}

t_bool		is_var_exist(char **envp, char *arg)
{
	int len_name;

	len_name = 0;
	while (arg[len_name] != '=')
		len_name++;
	while (*envp)
	{
		if (ft_strncmp(*envp, arg, len_name) == 0)
			return (TRUE);
		envp++;
	}
	return (FALSE);
}

/*
**	static function for var_replacement.
*/

static char	**var_finder(char **envp, char *arg)
{
	int len_name;

	len_name = 0;
	while (arg[len_name] != '=')
		len_name++;
	while (*envp)
	{
		if (ft_strncmp(*envp, arg, len_name) == 0)
			return (envp);
		envp++;
	}
	return (NULL);
}

/*
**	This function will replace the value of a variable in envp.
**	Return ERR_MALLOC or 0 if success.
*/

int			var_replacement(char **envp, char *arg)
{
	char **to_replace;

	to_replace = var_finder(envp, arg);
	free(*to_replace);
	if (!(*to_replace = ft_strdup(arg)))
		return (ERR_MALLOC);
	return (0);
}
