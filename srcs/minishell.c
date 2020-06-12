/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 09:42:06 by jecaudal          #+#    #+#             */
/*   Updated: 2020/04/21 15:34:58 by Lobbyra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Mesure command length and return strdup_n of user_input by len mesured
*/
static char		*get_first_command(char *user_input)
{
	char	*index;

	index = user_input;
	while (ft_c_finder(*index, ";|") == FALSE && *index)
		index++;
	if (*index)
		index--;
	return (ft_strdup_n(user_input, index - user_input));
}

/*
** Will cut the first command of user_input.
*/
static char		*next_command(char *user_input)
{
	char	*ret;
	char	*index;

	index = user_input;
	while (ft_c_finder(*index, ";|") == FALSE && *index)
		index++;
	if (ft_c_finder(*index, "|;") == TRUE)
		index++;
	while (*index == ' ')
		index++;
	ret = ft_strdup(index);
	free(user_input);
	return (ret);
}

int				minishell(t_stock *s)
{
	int error;

	while (ft_strcmp(s->user_input, "") != 0)
	{
		error = 0;
		if ((s->command = get_first_command(s->user_input)) == NULL)
			return (ERR_MALLOC);
		if (ft_strcmp(s->command, "exit") == 0 && (s->ill_exit = TRUE))
			return (0);
		if ((error = parsing(&(s->command), s->storage_return, s->envp)) != 0)
			print_err_parsing(error);
		if (s->is_debug_mode == TRUE)
			print_t_stock(s);
		if (error == 0 && (error = execution(s)) != 0)
			print_err_execution(error);
		if ((s->user_input = next_command(s->user_input)) == NULL)
			return (1);
	}
	return (0);
}
