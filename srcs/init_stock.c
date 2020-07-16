/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:26:06 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/16 16:03:34 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_stock	*panic_init_stock(t_stock *stock)
{
	if (stock->envp)
		ft_freestrs(stock->envp);
	if (stock)
		free(stock);
	return (NULL);
}

static void		iter_shlvl(char **envp)
{
	int	lvl;

	while (*envp)
	{
		if (ft_strncmp("SHLVL=", *envp, 6) == 0)
		{
			lvl = ft_atoi((*envp) + 6);
			lvl++;
			free(*envp);
			*envp = ft_strjoindel("SHLVL=", ft_itoa(lvl), 2);
		}
		envp++;
	}
}

t_stock			*init_stock(char **envp)
{
	t_stock	*new;

	if (!(new = (t_stock*)malloc(sizeof(t_stock))))
		return (NULL);
	if (!(new->envp = ft_strarrdup(envp)))
		return (panic_init_stock(new));
	iter_shlvl(new->envp);
	new->jobs = NULL;
	new->pipes = NULL;
	new->error_strings = NULL;
	new->exit_status = 0;
	new->user_input = NULL;
	new->buf_user_input = NULL;
	new->list_exec_abort = NULL;
	return (new);
}
