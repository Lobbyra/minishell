/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_and_replace_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:47:13 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/07/17 17:01:49 by jereligi         ###   ########.fr       */
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

char	*remove_and_replace_utils(char *input, char *new, char **value)
{
	int		i;
	int		n;
	int		x;
	int		quot;

	i = 0;
	n = 0;
	x = 0;
	quot = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
			word_between_simple_quote(&i, input, &quot);
		if (input[i] == '$' && input[i - 1] != '\\' && (quot == 0 || quot == 2))
		{
			i++;
			while (input[i] && (ft_isalnum(input[i]) || input[i] == '?'))
				i++;
			n = n + remplace_env_var(new + n, value[x++]);
		}
		else
			new[n++] = input[i++];
	}
	new[n] = '\0';
	return (new);
}
