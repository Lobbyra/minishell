/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_and_replace_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:47:13 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/07/23 16:18:29 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function is the continuation of env_var.c 
**	(replaces a environment variable by this value)
*/

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

char		*escape_env_var(char *new, char *value, int *i, int *n)
{
	int x;

	x = 0;
	while (value[*i + x] != '\0' && value[*i + x] == '\\')
		x++;
	if ((is_metacharacter(value[*i + x])) == 1 || value[*i + x] == '|')
	{
		new[(*n)++] = '\'';
		new[(*n)++] = value[(*i)++];
		while (value[*i] != '\0' && value[*i] == '\\')
			new[(*n)++] = value[(*i)++];
		new[(*n)++] = value[(*i)++];
		new[(*n)++] = '\'';
	}
	return (new);
}

int			remplace_env_var(char *new, char *value)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (value[i])
	{
		if (value[i] == '\\')
			new = escape_env_var(new, value, &i, &n);
		if ((is_metacharacter(value[i]) || value[i] == '|') && \
		!is_escaped(value, i))
		{
			new[n++] = '\'';
			new[n++] = value[i++];
			new[n++] = '\'';
		}
		else
			new[n++] = value[i++];
	}
	new[n] = '\0';
	return (n);
}

char	*remove_and_replace_utils(char *ui, char *new, char **value)
{
	int		i;
	int		n;
	int		x;
	int		quot;

	i = 0;
	n = 0;
	x = 0;
	quot = 0;
	while (ui[i])
	{
		if (ui[i] == '\'' || ui[i] == '"')
			word_between_simple_quote(&i, ui, &quot);
		if (ui[i] == '$' && ui[i - 1] != '\\' && (quot == 0 || quot == 2))
		{
			i++;
			while (ui[i] && (ft_isalnum(ui[i]) || ui[i] == '?' || ui[i] == '_'))
				i++;
			n = n + remplace_env_var(new + n, value[x++]);
		}
		else
			new[n++] = ui[i++];
	}
	new[n] = '\0';
	return (new);
}
