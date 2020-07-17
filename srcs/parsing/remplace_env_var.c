/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplace_env_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 17:17:46 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/17 16:19:36 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
