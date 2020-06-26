/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:49:08 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/26 16:02:39 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		print_export_err(char *arg)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

static t_bool	is_correct_name(char *arg)
{
	t_bool letter_saw;

	letter_saw = FALSE;
	while (*arg && *arg != '=')
	{
		if (!(*arg >= 'a' && *arg <= 'z') && !(*arg >= '0' && *arg <= '9')
			&& !(*arg >= 'A' && *arg <= 'Z') && *arg != '_')
			return (FALSE);
		if ((*arg >= 'a' && *arg <= 'z') || (*arg >= 'a' && *arg <= 'z'))
			letter_saw = TRUE;
		if (*arg >= '0' && *arg <= '9' && letter_saw == FALSE)
			return (FALSE);
		arg++;
	}
	return (TRUE);
}

static t_bool	is_an_egual(char *arg)
{
	while (*arg)
	{
		if (*arg == '=')
			return (TRUE);
		arg++;
	}
	return (FALSE);
}

static int		envp_modification(char ***envp, char *arg)
{
	char **tmp;

	if (is_var_exist(*envp, arg) == TRUE)
	{
		if (var_replacement(*envp, arg) != 0)
			return (ERR_MALLOC);
	}
	else
	{
		if (!(tmp = ft_addstr_to_strs(*envp, arg)))
			return (ERR_MALLOC);
		ft_freestrs(*envp);
		*envp = tmp;
	}
	return (0);
}

int				export(char ***envp, char **job, int fd)
{
	int		i;
	int		err;

	i = 1;
	err = 0;
	if (!job[i])
		print_envp_export(*envp, fd);
	while (job[i])
	{
		if (is_correct_name(job[i]) == FALSE)
			err = print_export_err(job[i]);
		else if (is_an_egual(job[i]) == TRUE)
		{
			if (envp_modification(envp, job[i]) != 0)
				return (ERR_MALLOC);
		}
		i++;
	}
	return (err);
}

/*
int		main(int argc, char **argv, char **envp)
{
	char **dup_envp;
	char *test[2] = {"export", NULL};

	if (argc >= 2)
	{
		dup_envp = ft_strarrdup(envp);
		// l_printf("Envp before addition :\n\n");
		// print_envp_export(dup_envp, 1);
		// l_printf("----------------------------\n\n");
		printf("export = %d\n", export(&dup_envp, argv + 1, 1));
		// export(&dup_envp, argv + 1, 1);
		export(&dup_envp, test, 1);
		// l_printf("Envp after addition :\n\n");
		// print_envp_export(dup_envp, 1);
		ft_freestrs(dup_envp);
	}
	return (0);
}

__attribute__((destructor)) static void leak() { getchar(); }
*/
