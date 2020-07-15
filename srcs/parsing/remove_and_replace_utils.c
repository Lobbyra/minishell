/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_and_replace_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:47:13 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/07/15 15:05:54 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_env_exit_status(char *env_var, char **value, int i, t_stock *s)
{
	int	len_var;

	len_var = ft_strlen(env_var);
	if (ft_strncmp(env_var, "?", len_var) == 0)
	{
		free(value[i]);
		value[i] = ft_itoa(s->exit_status);
	}
}

void	word_between_simple_quote(int *i, char *user_input, int *quote)
{
	if ((user_input[*i] == '\"' && *quote == 0)
	&& (!is_escape(*i, user_input)))
		*quote = 2;
	else if ((user_input[*i] == '\'' && *quote == 0)
	&& (!is_escape(*i, user_input)))
		*quote = 1;
	else if ((*quote == 1 && user_input[*i] == '\'') && \
	(!is_escape(*i, user_input)))
		*quote = 0;
	else if ((*quote == 2 && user_input[*i] == '\"') && \
	(!is_escape(*i, user_input)))
		*quote = 0;
}

char	*remove_and_replace_utils(char *user_input, char *new, char **value)
{
	int		i;
	int		n;
	int		x;
	int		quote;

	i = 0;
	n = 0;
	x = 0;
	quote = 0;
	while (user_input[i])
	{
		if (user_input[i] == '\'' || user_input[i] == '"')
			word_between_simple_quote(&i, user_input, &quote);
		if (user_input[i] == '$' && user_input[i - 1] != '\\' && (quote == 0 || quote == 2))
		{
			i++;
			while (user_input[i] && (ft_isalnum(user_input[i]) || user_input[i] == '?'))
				i++;
			n = n + remplace_env_var(new + n, value[x]);
			x++;
		}
		else
			new[n++] = user_input[i++];
	}
	new[n] = '\0';
	return (new);
}
