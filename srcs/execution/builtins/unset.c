/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:42:06 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/24 16:08:29 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This is the code source of minishell builtin of unset.
**	This function will
*/

#include "minishell.h"

static int		print_unset_err(char *arg)
{
	ft_putstr_fd("minishell: unset: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

static t_bool	is_correct_name(char *arg)
{
	t_bool letter_saw;

	letter_saw = FALSE;
	while (*arg)
	{
		if (!(*arg >= 'a' && *arg <= 'z') && !(*arg >= '0' && *arg <= '9')
			&& !(*arg >= 'A' && *arg <= 'Z') && *arg != '_')
			return (FALSE);
		if ((*arg >= 'a' && *arg <= 'z') || (*arg >= 'A' && *arg <= 'Z'))
			letter_saw = TRUE;
		if (*arg >= '0' && *arg <= '9' && letter_saw == FALSE)
			return (FALSE);
		arg++;
	}
	return (TRUE);
}

static char		**panic_var_deletion(char **new, char **i_new)
{
	while (i_new > new)
	{
		free(*i_new);
		i_new--;
	}
	free(new);
	return (NULL);
}

static char		**var_deletion(char **save_envp, char **envp, char *var)
{
	char	**new;
	char	**i_new;

	if (!(new = (char**)malloc(sizeof(char*) * (ft_strarrlen(envp) - 1 + 1))))
		return (NULL);
	i_new = new;
	while (*envp)
	{
		if (ft_strncmp(*envp, var, ft_strlen_c(*envp, '=')) != 0)
		{
			if (!(*i_new = ft_strdup(*envp)))
				return (panic_var_deletion(new, i_new));
			i_new++;
		}
		envp++;
	}
	*i_new = NULL;
	ft_freestrs(save_envp);
	return (new);
}

int				unset(char ***envp, char **job)
{
	int i;

	i = 1;
	while (job[i])
	{
		if (is_correct_name(job[i]) == FALSE || ft_strcmp("", job[i]) == 0)
			print_unset_err(job[i]);
		else if (is_var_exist(*envp, job[i]) == TRUE &&
				!(*envp = var_deletion(*envp, *envp, job[i])))
			return (ERR_MALLOC);
		i++;
	}
	return (0);
}
