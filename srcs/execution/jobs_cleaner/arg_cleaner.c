/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:18:59 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/16 18:45:32 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function will return the argument cleaned of separator quotes
**	and escaper.
*/

#include "minishell.h"

static char	*add_nquote(char *new, char *arg, int i)
{
	char *buf;

	if (!(buf = ft_strdup_n(arg + i, part_len_nquote(arg, i))))
		return (NULL);
	escaper_nquote(buf);
	return (ft_strjoindel(new, buf, 3));
}

static char	*add_quote(char *new, char *arg, int i)
{
	char *buf;

	if (!(buf = ft_strdup_n(arg + i + 1, part_len_quote(arg, i) - 2)))
		return (NULL);
	return (ft_strjoindel(new, buf, 3));
}

static char	*add_dquote(char *new, char *arg, int i)
{
	char *buf;

	if (!(buf = ft_strdup_n(arg + i + 1, part_len_dquote(arg, i) - 2)))
		return (NULL);
	escaper_dquote(buf);
	return (ft_strjoindel(new, buf, 3));
}

char		*arg_cleaner(char *arg)
{
	int		i;
	char	*new;

	if (!(new = (char*)malloc(sizeof(char))))
		return (NULL);
	new[0] = '\0';
	i = 0;
	while (arg[i])
	{
		if (arg[i] != '\"' && arg[i] != '\'')
			new = add_nquote(new, arg, i);
		else if (arg[i] == '\"')
			new = add_dquote(new, arg, i);
		else if (arg[i] == '\'')
			new = add_quote(new, arg, i);
		pass_part(arg, &i);
	}
	return (new);
}
